using Newtonsoft.Json.Linq;

namespace courseworkWinFormsCSharp.OrderComponents
{
    public class Order
    {
        public static int LastID = 0;

        public int ID { get; private set; }
        public Laptop Laptop { get; set; }
        public StatusType Status { get; set; }
        public string AdditionalInfo { get; set; }

        public Order()
        {
            ID = ++LastID;
        }

        public Order(Laptop Laptop) : this()
        {
            this.Laptop = Laptop;
        }

        public Order(Laptop Laptop, StatusType Status, string AdditionalInfo) : this(Laptop)
        {
            this.Status = Status;
            this.AdditionalInfo = AdditionalInfo;
        }

        public Order(JObject j)
        {
            FromJSON(j);
            ++LastID;
        }

        public static int GetLastID()
        {
            return LastID;
        }

        public override string ToString()
        {
            return ID + ". " + Laptop.ModelName + "\t" + Status.ToString() + '\t' + AdditionalInfo;
        }

        public JObject ToJSON()
        {
            JObject json = new JObject() 
            {
                { "numOfOrder", ID },
                { "laptop", Laptop.ToJSON() },
                { "status", Status.ToString() },
                { "additionalInfo", AdditionalInfo }
            };
            return json;
        }

        public void FromJSON(JObject j)
        {
            ID = j.GetValue("numOfOrder").ToObject<int>();
            Laptop.FromJSON(j.GetValue("laptop").ToObject<JObject>());
            Status = StatusTypeConverter.StringToStatusType(j.GetValue("status").ToString());
            AdditionalInfo = j.GetValue("additionalInfo").ToString();
        }
    }
}
