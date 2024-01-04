using Newtonsoft.Json.Linq;

namespace courseworkWinFormsCSharp.OrderComponents
{
    public class Motherboard : ILaptopComponent
    {
        public string ModelName
        {
            get => ModelName;
            set => ModelName = value;
        }
        public string Socket
        {
            get => Socket;
            set => Socket = value;
        }
        public string Chipset
        {
            get => Chipset; 
            set => Chipset = value;
        }
        public RAMType SupportedRAMType
        {
            get => SupportedRAMType;
            set => SupportedRAMType = value;
        }

        public Motherboard(string ModelName)
        {
            this.ModelName = ModelName;
        }

        public Motherboard(string ModelName, string Socket, string Chipset, RAMType SupportedRAMType)
        {
            SetArguments(ModelName, Socket, Chipset, SupportedRAMType);
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
                { "supportedRAMType", RAMTypeConverter.RAMTypeToString(SupportedRAMType) }
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

        private void SetArguments(string ModelName, string Socket, string Chipset, RAMType SupportedRAMType)
        {
            this.ModelName = ModelName;
            this.Socket = Socket;
            this.Chipset = Chipset;
            this.SupportedRAMType = SupportedRAMType;
        }
    }
}
