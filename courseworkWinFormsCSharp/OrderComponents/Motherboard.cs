using Newtonsoft.Json.Linq;

namespace courseworkWinFormsCSharp.OrderComponents
{
    public class Motherboard : ILaptopComponent
    {
        public string ModelName { get; set; } = string.Empty;
        public string Socket { get; set; } = string.Empty;
        public string Chipset { get; set; } = string.Empty;
        public RAMType SupportedRAMType { get; set; } = RAMType.DDR4;

        public Motherboard() { }
        public Motherboard(string ModelName)
        {
            this.ModelName = ModelName;
        }

        public Motherboard(string ModelName, string Socket, string Chipset, RAMType SupportedRAMType)
        {
            this.ModelName = ModelName;
            this.Socket = Socket;
            this.Chipset = Chipset;
            this.SupportedRAMType = SupportedRAMType;
        }

        public Motherboard(JObject j)
        {
            FromJSON(j);
        }

        public string GetComponentName() => "Motherboard";

        public override string ToString()
        {
            return $"{ModelName}, {Socket}, {Chipset}";
        }

        public JObject ToJSON()
        {
            JObject j = new JObject
            {
                { "modelName", ModelName },
                { "socket", Socket },
                { "chipset", Chipset },
                { "supportedRAMType", SupportedRAMType.ToString() }
            };
            return j;
        }

        public void FromJSON(JObject j)
        {
            ModelName = j.GetValue("modelName").ToString();
            Socket = j.GetValue("socket").ToString();
            Chipset = j.GetValue("chipset").ToString();
            SupportedRAMType = RAMTypeConverter.StringToRAMType(j.GetValue("supportedRAMType").ToString());
        }
    }
}
