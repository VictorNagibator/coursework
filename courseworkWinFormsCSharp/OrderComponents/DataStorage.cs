using Newtonsoft.Json.Linq;
using System;

namespace courseworkWinFormsCSharp.OrderComponents
{
    public abstract class DataStorage : ILaptopComponent
    {
        public int Capacity
        {
            get => Capacity;
            set => TryToSetArguments(value, TransferInterface, Brand, FormFactor);
        }
        public DataTransferInterface TransferInterface
        {
            get => TransferInterface;
            set => TryToSetArguments(Capacity, value, Brand, FormFactor);
        }
        public string Brand
        {
            get => Brand;
            set => TryToSetArguments(Capacity, TransferInterface, value, FormFactor);
        }
        public float FormFactor
        {
            get => FormFactor;
            set => TryToSetArguments(Capacity, TransferInterface, Brand, value);
        }

        public DataStorage(DataTransferInterface TransferInterface)
        {
            this.TransferInterface = TransferInterface;
        }

        public DataStorage(int Capacity, DataTransferInterface TransferInterface, string Brand, float FormFactor)
        {
            TryToSetArguments(Capacity, TransferInterface, Brand, FormFactor);
        }

        public DataStorage(JObject json)
        {
            FromJSON(json);
        }

        public abstract string GetComponentName();


        public override string ToString()
        {
            return $"{Brand}, {Capacity} ГБ, {TransferInterface}, {FormFactor:F1}";
        }

        public virtual JObject ToJSON()
        {
            JObject json = new JObject
            {
                { "componentName", GetComponentName() },
                { "capacity", Capacity },
                { "transferInterface", TransferInterface.ToString() },
                { "brand", Brand },
                { "formFactor", FormFactor }
            };
            return json;
        }

        public virtual void FromJSON(JObject data)
        {
            TryToSetArguments(data.GetValue("capacity").ToObject<int>(), DataTransferInterfaceConverter.StringToDataTransferInterface(data.GetValue("transferInterface").ToString()), data.GetValue("brand").ToString(), data.GetValue("formFactor").ToObject<float>());
        }

        private bool CheckArguments(int Capacity, DataTransferInterface TransferInterface, string Brand, float FormFactor)
        {
            return Capacity >= 0 && FormFactor >= 0;
        }

        private void TryToSetArguments(int Capacity, DataTransferInterface TransferInterface, string Brand, float FormFactor)
        {
            if (CheckArguments(Capacity, TransferInterface, Brand, FormFactor))
            {
                this.Capacity = Capacity;
                this.TransferInterface = TransferInterface;
                this.Brand = Brand;
                this.FormFactor = FormFactor;
            }
            else
            {
                throw new ArgumentException("Некорректный формат данных!");
            }
        }
    }
}
