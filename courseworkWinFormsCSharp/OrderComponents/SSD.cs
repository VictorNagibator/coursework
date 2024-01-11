using Newtonsoft.Json.Linq;
using System;

namespace courseworkWinFormsCSharp.OrderComponents
{
    public class SSD : DataStorage
    {
        public FlashMemoryType TypeOfFlashMemory { get; set; } = FlashMemoryType.NAND3D;

        public SSD(DataTransferInterface transferInterface) : base(transferInterface) { }

        public SSD(int Capacity, DataTransferInterface TransferInterface, string Brand, float FormFactor, FlashMemoryType TypeOfFlashMemory)
            : base(Capacity, TransferInterface, Brand, FormFactor)
        {
            this.TypeOfFlashMemory = TypeOfFlashMemory;
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

        public override JObject ToJSON()
        {
            JObject json = base.ToJSON();
            json["typeOfFlashMemory"] = TypeOfFlashMemory.ToString();
            return json;
        }

        public override void FromJSON(JObject json)
        {
            base.FromJSON(json);
            TypeOfFlashMemory = FlashMemoryTypeConverter.StringToFlashMemoryType(json.GetValue("typeOfFlashMemory").ToString());
        }
    }
}
