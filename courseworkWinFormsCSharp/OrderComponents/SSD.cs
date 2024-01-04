using Newtonsoft.Json.Linq;
using System;

namespace courseworkWinFormsCSharp.OrderComponents
{
    public class SSD : DataStorage
    {
        public FlashMemoryType TypeOfFlashMemory { get; set; }

        public SSD(DataTransferInterface transferInterface) : base(transferInterface)
        {

        }

        public SSD(int Capacity, DataTransferInterface TransferInterface, string Brand, float FormFactor, FlashMemoryType TypeOfFlashMemory)
            : base(Capacity, TransferInterface, Brand, FormFactor)
        {
            SetArguments(TypeOfFlashMemory);
        }

        public SSD(JObject json) : base(json)
        {
            FromJSON(json);
        }

        public override string GetComponentName() => "SSD";

        public override string ToString()
        {
            return base.ToString() + ", " + TypeOfFlashMemory.ToString();
        }

        public JObject ToJSON()
        {
            JObject json = base.ToJSON();
            json["typeOfFlashMemory"] = TypeOfFlashMemory.ToString();
            return json;
        }

        public void FromJSON(JObject json)
        {
            base.FromJSON(json);
            SetArguments(json.GetValue("typeOfFlashMemory").ToObject<FlashMemoryType>());
        }

        private void SetArguments(FlashMemoryType typeOfFlashMemory)
        {
            TypeOfFlashMemory = typeOfFlashMemory;
        }
    }
}
