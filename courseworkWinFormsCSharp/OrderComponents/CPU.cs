using System;
using Newtonsoft.Json.Linq;

namespace courseworkWinFormsCSharp.OrderComponents
{
    internal class CPU : ILaptopComponent
    {
        public string ModelName { get; set; } = string.Empty;
        public string Socket { get; set; } = string.Empty;
        public double Frequency { get; set; }
        public int NumOfCores { get; set; }

        private const double MaxFreq = 9.0;
        private const double TryFreq = 0.2; 

        public CPU()
        {

        }

        public CPU(string ModelName)
        {
            this.ModelName = ModelName;
        }

        public string GetComponentName() => "CPU";

        public CPU(string ModelName, string Socket, float Frequency, int NumOfCores)
        {
            TryToSetArguments(ModelName, Socket, Frequency, NumOfCores);
        }

        public override string ToString()
        {
            return $"{ModelName}, {Socket}, {Frequency:F1} ГГц, {NumOfCores}-ядерный";
        }

        public JObject ToJson()
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

        public void FromJson(JObject cpu)
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
