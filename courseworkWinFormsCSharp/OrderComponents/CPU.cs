using System;
using Newtonsoft.Json.Linq;

namespace courseworkWinFormsCSharp.OrderComponents
{
    public class CPU : ILaptopComponent
    {
        public string ModelName
        {
            get => ModelName;
            set => TryToSetArguments(value, Socket, Frequency, NumOfCores);
        }
        public string Socket
        {
            get => Socket;
            set => TryToSetArguments(ModelName, value, Frequency, NumOfCores);
        }
        public float Frequency
        {
            get => Frequency;
            set => TryToSetArguments(ModelName, Socket, value, NumOfCores);
        }
        public int NumOfCores
        {
            get => NumOfCores;
            set => TryToSetArguments(ModelName, Socket, Frequency, value);
        }

        private const float MaxFreq = 9.0f;
        private const float TryFreq = 0.2f; 

        public CPU()
        {
            ModelName = string.Empty;
            Socket = string.Empty;
        }

        public CPU(string ModelName) : this()
        {
            this.ModelName = ModelName;
        }

        public CPU(string ModelName, string Socket, float Frequency, int NumOfCores)
        {
            TryToSetArguments(ModelName, Socket, Frequency, NumOfCores);
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
            TryToSetArguments(cpu.GetValue("modelName").ToString(), cpu.GetValue("socket").ToString(), cpu.GetValue("frequency").ToObject<float>(), cpu.GetValue("numOfCores").ToObject<int>());
        }

        private bool CheckArguments(string ModelName, string Socket, float Frequency, int NumOfCores)
        {
            return Frequency >= 0 && Frequency < MaxFreq && NumOfCores >= 0;
        }

        private void TryToSetArguments(string ModelName, string Socket, float Frequency, int NumOfCores)
        {
            if (CheckArguments(ModelName, Socket, Frequency, NumOfCores))
            {
                this.ModelName = ModelName;
                this.Socket = Socket;
                this.Frequency = Frequency;
                this.NumOfCores = NumOfCores;
            }
            else
            {
                throw new ArgumentException("Некорректный формат данных!");
            }
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
