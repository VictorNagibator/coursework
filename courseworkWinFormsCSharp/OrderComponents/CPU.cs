using System;
using Newtonsoft.Json.Linq;

namespace courseworkWinFormsCSharp.OrderComponents
{
    public class CPU : ILaptopComponent
    {
        public string ModelName { get; set; } = string.Empty;
        public string Socket { get; set; } = string.Empty;
        private float _frequency;
        public float Frequency
        {
            get => _frequency;
            set
            {
                if (value >= 0 && value < MaxFreq)
                    _frequency = value;
                else
                    throw new ArgumentException("Некорректная частота CPU!");
            }
        }
        private int _numOfCores;
        public int NumOfCores
        {
            get => _numOfCores;
            set
            { 
                if (value >= 0)
                    _numOfCores = value;
                else
                    throw new ArgumentException("Некорректное количество ядер CPU!");
            }
        }

        private const float MaxFreq = 9.0f;
        private const float TryFreq = 0.2f; 

        public CPU() { }

        public CPU(string ModelName)
        {
            this.ModelName = ModelName;
        }

        public CPU(string ModelName, string Socket, float Frequency, int NumOfCores)
        {
            this.ModelName = ModelName;
            this.Socket = Socket;
            this.Frequency = Frequency;
            this.NumOfCores = NumOfCores;
        }

        public CPU(JObject json)
        {
            FromJSON(json);
        }

        public string GetComponentName() => "CPU";

        public override string ToString()
        {
            return $"{ModelName}, {Socket}, {Frequency:F1} ГГц, {NumOfCores}-ядерный";
        }

        public JObject ToJSON()
        {
            JObject json = new JObject
            {
                { "modelName", ModelName },
                { "socket", Socket },
                { "frequency", Frequency },
                { "numOfCores", NumOfCores }
            };
            return json;
        }

        public void FromJSON(JObject cpu)
        {
            ModelName = cpu.GetValue("modelName").ToString();
            Socket = cpu.GetValue("socket").ToString();
            Frequency = cpu.GetValue("frequency").ToObject<float>();
            NumOfCores = cpu.GetValue("numOfCores").ToObject<int>();
        }

        public static CPU operator +(CPU cpu, float addable)
        {
            cpu.Frequency += addable;
            return cpu;
        }

        public static CPU operator ++(CPU cpu)
        {
            cpu.Frequency += TryFreq;
            return cpu;
        }
    }
}