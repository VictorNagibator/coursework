using Newtonsoft.Json.Linq;
using System;

namespace courseworkWinFormsCSharp.OrderComponents
{
    public abstract class DataStorage : ILaptopComponent
    {
        private int _capacity;
        public int Capacity
        {
            get => _capacity;
            set
            {
                if (value >= 0)
                    _capacity = value;
                else
                    throw new ArgumentException("Некорректный объем памяти!");
            }
        }
        public DataTransferInterface TransferInterface { get; set; } = DataTransferInterface.SATA;
        public string Brand { get; set; } = string.Empty;

        private float _formFactor;
        public float FormFactor
        {
            get => _formFactor;
            set
            {
                if (value >= 0)
                    _formFactor = value;
                else
                    throw new ArgumentException("Некорректный форм-фактор!");
            }
        }

        public DataStorage() { }

        public DataStorage(DataTransferInterface TransferInterface)
        {
            this.TransferInterface = TransferInterface;
        }

        public DataStorage(int Capacity, DataTransferInterface TransferInterface, string Brand, float FormFactor)
        {
            this.Capacity = Capacity;
            this.TransferInterface = TransferInterface;
            this.Brand = Brand;
            this.FormFactor = FormFactor;
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
            Capacity = data.GetValue("capacity").ToObject<int>();
            TransferInterface = DataTransferInterfaceConverter.StringToDataTransferInterface(data.GetValue("transferInterface").ToString());
            Brand = data.GetValue("brand").ToString();
            FormFactor = data.GetValue("formFactor").ToObject<float>();
        }
    }
}
