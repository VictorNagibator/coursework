using Newtonsoft.Json.Linq;
using System;

namespace courseworkWinFormsCSharp.OrderComponents
{
    public class HDD : DataStorage
    {
        private int _spindleSpeed;
        public int SpindleSpeed
        {
            get => _spindleSpeed;
            set
            {
                if (value >= 0)
                    _spindleSpeed = value;
                else
                    throw new ArgumentException("Некорректная скорость шпинделя!");
            }
        }

        public HDD() : base() { }
        public HDD(DataTransferInterface TransferInterface) : base(TransferInterface) { }
        public HDD(int Capacity, DataTransferInterface TransferInterface, string Brand, float FormFactor, int SpindleSpeed)
            : base(Capacity, TransferInterface, Brand, FormFactor)
        {
            this.SpindleSpeed = SpindleSpeed;
        }

        public HDD(JObject json) : base(json)
        { 
            FromJSON(json);
        }

        public override string GetComponentName() => "HDD";

        public override string ToString()
        {
            return base.ToString() + $", {SpindleSpeed}";
        }

        public override JObject ToJSON()
        {
            JObject hdd = base.ToJSON();
            hdd["spindleSpeed"] = SpindleSpeed;
            return hdd;
        }

        public override void FromJSON(JObject hdd)
        {
            base.FromJSON(hdd);
            SpindleSpeed = hdd.GetValue("spindleSpeed").ToObject<int>();
        }
    }
}
