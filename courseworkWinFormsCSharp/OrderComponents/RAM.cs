using Newtonsoft.Json.Linq;
using System;
using System.Collections.Generic;

namespace courseworkWinFormsCSharp.OrderComponents
{
    public class RAM : ILaptopComponent
    {
        public string ModelName
        {
            get => ModelName;
            set => TryToSetArguments(value, Type, Frequency, Capacity);
        }
        public RAMType Type
        {
            get => Type;
            set => TryToSetArguments(ModelName, value, Frequency, Capacity);
        }
        public float Frequency
        {
            get => Frequency;
            set => TryToSetArguments(ModelName, Type, value, Capacity);
        }
        public int Capacity
        {
            get => Capacity;
            set => TryToSetArguments(ModelName, Type, Frequency, value);
        }

        private static readonly List<int> DDRFreqMax = new List<int> { 400, 1066, 2400, 3333, 6400 };
        private const float TryFreq = 50;

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
            TryToSetArguments(ModelName, Type, Frequency, Capacity);
        }

        public RAM(JObject json)
        {
            FromJSON(json);
        }

        public string GetComponentName() => "RAM";


        public override string ToString()
        {
            return $"{ModelName}, {RAMTypeConverter.RAMTypeToString(Type)}, {Capacity} ГБ, {Frequency:F1} МГц";
        }

        public JObject ToJSON()
        {
            JObject json = new JObject
            {
                { "modelName", ModelName },
                { "type", RAMTypeConverter.RAMTypeToString(Type) },
                { "frequency", Frequency },
                { "capacity", Capacity }
            };
            return json;
        }

        public void FromJSON(JObject json)
        {
            TryToSetArguments(json.GetValue("modelName").ToString(), RAMTypeConverter.StringToRAMType(json.GetValue("type").ToString()), json.GetValue("frequency").ToObject<float>(), json.GetValue("capacity").ToObject<int>());
        }

        private bool CheckArguments(string ModelName, RAMType Type, float Frequency, int Capacity)
        {
            return Frequency >= 0 && Frequency <= DDRFreqMax[RAMTypeConverter.RAMTypeToInt(Type)] && Capacity >= 0;
        }

        private void TryToSetArguments(string ModelName, RAMType Rype, float Frequency, int Capacity)
        {
            if (CheckArguments(ModelName, Type, Frequency, Capacity))
            {
                this.ModelName = ModelName;
                this.Type = Type;
                this.Frequency = Frequency;
                this.Capacity = Capacity;
            }
            else
            {
                throw new ArgumentException("Некорректный формат данных!");
            }
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
