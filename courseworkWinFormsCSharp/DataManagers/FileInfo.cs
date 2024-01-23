using Newtonsoft.Json.Linq;
using System.IO;

namespace courseworkWinFormsCSharp.DataManagers
{
    internal static class FileInfo
    {
        private static string path = null;
        public static string Path
        {
            get
            {
                if (string.IsNullOrEmpty(path))
                {
                    using (StreamReader properties = new StreamReader("..\\properties.json"))
                    {
                        path = JObject.Parse(properties.ReadToEnd()).GetValue("lastFile").ToString();
                    }
                }
                return path;
            }
            set
            {
                path = value;
                OrdersData.LoadOrders(path);
            }
        }
    }
}
