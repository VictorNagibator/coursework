using Newtonsoft.Json.Linq;
using System;

namespace courseworkWinFormsCSharp.OrderComponents
{
    public class HDD : DataStorage
    {
        public int SpindleSpeed
        {
            get => SpindleSpeed;
            set => TryToSetArguments(value);
        }

        public HDD(DataTransferInterface TransferInterface) : base(TransferInterface) { }

        public HDD(int Capacity, DataTransferInterface TransferInterface, string Brand, float FormFactor, int SpindleSpeed)
            : base(Capacity, TransferInterface, Brand, FormFactor)
        {
            TryToSetArguments(SpindleSpeed);
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
            TryToSetArguments(hdd.GetValue("spindleSpeed").ToObject<int>());
        }

        private bool CheckArguments(int SpindleSpeed)
        {
            return SpindleSpeed >= 0;
        }

        private void TryToSetArguments(int SpindleSpeed)
        {
            if (CheckArguments(SpindleSpeed))
            {
                this.SpindleSpeed = SpindleSpeed;
            }
            else
            {
                throw new ArgumentException("Некорректный формат данных!");
            }
        }
    }
}
