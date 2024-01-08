using courseworkWinFormsCSharp.OrderComponents;
using System;
using System.Collections.Generic;
using System.Linq;
using System.IO;

namespace courseworkWinFormsCSharp.DataManagers
{
    internal enum OrderOperation
    {
        Adding,
        Editing,
        Removing
    }

    internal class OrderOperationHelper
    {
        internal static string ToString(OrderOperation operation)
        {
            switch (operation)
            {
                case OrderOperation.Adding:
                    return "добавлен";
                case OrderOperation.Editing:
                    return "изменен";
                case OrderOperation.Removing:
                    return "удален";
                default:
                    throw new ArgumentOutOfRangeException(nameof(operation), operation, null);
            }
        }
    }

    internal static class OrdersData
    {
        public static List<Order> Data { get; private set; } = new List<Order>();

        public static Order GetOrder(int idOfOrder)
        {
            var getOrder = Data.FirstOrDefault(order => order.ID == idOfOrder);

            if (getOrder != null)
            {
                return getOrder;
            }
            else
            {
                throw new ArgumentException("Заказа с таким ID не существует!");
            }
        }

        public static void LoadOrders(string filePath)
        {
            try
            {
                string jsonText = File.ReadAllText(filePath);
                var json = Newtonsoft.Json.JsonConvert.DeserializeObject<Newtonsoft.Json.Linq.JObject>(jsonText);
                Order order = new Order(json);
                Data.Add(order);
            }
            catch (Exception)
            {
                try
                {
                    var jsonArray = Newtonsoft.Json.JsonConvert.DeserializeObject<List<Newtonsoft.Json.Linq.JObject>>(File.ReadAllText(filePath));
                    foreach (var element in jsonArray)
                    {
                        Order order = new Order(element);
                        Data.Add(order);
                    }
                }
                catch (Exception)
                {
                    
                }
            }

            VerifyIDs();
        }

        public static void SaveOrders(string filePath)
        {
            var jsonList = Data.Select(order => Newtonsoft.Json.JsonConvert.DeserializeObject(order.ToJSON().ToString()));
            File.WriteAllText(filePath, Newtonsoft.Json.JsonConvert.SerializeObject(jsonList, Newtonsoft.Json.Formatting.Indented));
        }

        public static void AddOrder(Order order)
        {
            Data.Add(order);
            Logger.Log(order.ID, OrderOperation.Adding);
            VerifyIDs();
        }

        public static void RemoveOrder(int idOfOrder)
        {
            var removable = Data.FirstOrDefault(order => order.ID == idOfOrder);

            if (removable != null)
            {
                Data.Remove(removable);
                Logger.Log(idOfOrder, OrderOperation.Removing);
            }
            else
            {
                throw new ArgumentException("Заказа с таким ID не существует!");
            }
        }

        public static void EditOrder(Order newOrder)
        {
            var editable = Data.FirstOrDefault(order => order.ID == newOrder.ID);

            if (editable != null)
            {
                Data[Data.IndexOf(editable)] = newOrder;
                Logger.Log(newOrder.ID, OrderOperation.Editing);
            }
            else
            {
                throw new ArgumentException("Заказа с таким ID не существует!");
            }
        }

        public static void VerifyIDs()
        {
            var jsonText = File.ReadAllText("..\\properties.json");
            var j = Newtonsoft.Json.JsonConvert.DeserializeObject<Newtonsoft.Json.Linq.JObject>(jsonText);

            if (j[FileInfo.Path] == null)
            {
                j[FileInfo.Path] = 0;
            }
            int maxID = j[FileInfo.Path].ToObject<int>();
            if (maxID < Order.LastID)
            {
                j[FileInfo.Path] = Order.LastID;
            }
            else
            {
                while (Order.LastID < maxID)
                {
                    _ = new Order();
                }
            }

            File.WriteAllText("..\\properties.json", Newtonsoft.Json.JsonConvert.SerializeObject(j, Newtonsoft.Json.Formatting.Indented));
        }

        public static bool IsDataEmpty()
        {
            return Data.Count == 0;
        }
    }
}
