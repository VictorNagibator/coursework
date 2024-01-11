using Newtonsoft.Json.Linq;
using System;
using System.Collections.Generic;

namespace courseworkWinFormsCSharp.OrderComponents
{
    public class RAM : ILaptopComponent
    {
        public string ModelName { get; set; } = string.Empty;
        public RAMType Type { get; set; } = RAMType.DDR4;
        private float _frequency;
        public float Frequency
        {
            get => _frequency;
            set
            {
                if (value >= 0 && value <= DDRFreqMax[RAMTypeConverter.RAMTypeToInt(Type)])
                    _frequency = value;
                else
                    throw new ArgumentException("Некорректная частота RAM!");
            }
        }
        private int _capacity;
        public int Capacity
        {
            get => _capacity;
            set
            {
                if (value >= 0)
                    _capacity = value;
                else
                    throw new ArgumentException("Некорректный объем RAM!");
            }
        }

        private static readonly List<int> DDRFreqMax = new List<int> { 400, 1066, 2400, 3333, 6400 };
        private const float TryFreq = 50;

        public RAM() { }
        public RAM(string ModelName)
        {
            this.ModelName = ModelName;
        }

        public RAM(RAMType Type)
        {
            this.Type = Type;
        }

        public RAM(string ModelName, RAMType Type, float Frequency, int Capacity)
        {
            this.ModelName = ModelName;
            this.Type = Type;
            this.Frequency = Frequency;
            this.Capacity = Capacity;
        }

        public RAM(JObject json)
        {
            FromJSON(json);
        }

        public string GetComponentName() => "RAM";


        public override string ToString()
        {
            return $"{ModelName}, {Type}, {Capacity} ГБ, {Frequency:F1} МГц";
        }

        public JObject ToJSON()
        {
            JObject json = new JObject
            {
                { "modelName", ModelName },
                { "type", Type.ToString() },
                { "frequency", Frequency },
                { "capacity", Capacity }
            };
            return json;
        }

        public void FromJSON(JObject json)
        {
            ModelName = json.GetValue("modelName").ToString();
            Type = RAMTypeConverter.StringToRAMType(json.GetValue("type").ToString());
            Frequency = json.GetValue("frequency").ToObject<float>();
            Capacity = json.GetValue("capacity").ToObject<int>();
        }

        public static RAM operator +(RAM ram, float addable)
        {
            ram.Frequency += addable;
            return ram;
        }

        public static RAM operator ++(RAM ram)
        {
            ram.Frequency += TryFreq;
            return ram;
        }
    }
}
