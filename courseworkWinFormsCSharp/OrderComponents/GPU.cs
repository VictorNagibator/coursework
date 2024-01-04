using Newtonsoft.Json.Linq;
using System;

namespace courseworkWinFormsCSharp.OrderComponents
{
    public class GPU : ILaptopComponent
    {
        public string ModelName
        {
            get => ModelName;
            set => TryToSetArguments(value, Frequency, VRAM);
        }
        public float Frequency
        {
            get => Frequency;
            set => TryToSetArguments(ModelName, value, VRAM);
        }
        public int VRAM
        {
            get => VRAM;
            set => TryToSetArguments(ModelName, Frequency, value);
        }

        public GPU()
        {
            ModelName = string.Empty;
        }

        public GPU(string ModelName)
        {
            this.ModelName = ModelName;
        }

        public GPU(string ModelName, float Frequency, int VRAM)
        {
            TryToSetArguments(ModelName, Frequency, VRAM);
        }

        public GPU(JObject json)
        {
            FromJSON(json);
        }
        public string GetComponentName() => "GPU";

        public override string ToString()
        {
            return $"{ModelName}, {Frequency:F1} МГц, {VRAM} ГБ";
        }

        public JObject ToJSON()
        {
            JObject json = new JObject
            {
                { "modelName", ModelName },
                { "frequency", Frequency },
                { "vram", VRAM }
            };
            return json;
        }

        public void FromJSON(JObject gpu)
        {
            TryToSetArguments(gpu.GetValue("modelName").ToString(), gpu.GetValue("frequency").ToObject<float>(), gpu.GetValue("vram").ToObject<int>());
        }

        private bool CheckArguments(string ModelName, float Frequency, int VRAM)
        {
            return Frequency >= 0 && VRAM >= 0;
        }

        private void TryToSetArguments(string ModelName, float Frequency, int VRAM)
        {
            if (CheckArguments(ModelName, Frequency, VRAM))
            {
                this.ModelName = ModelName;
                this.Frequency = Frequency;
                this.VRAM = VRAM;
            }
            else
            {
                throw new ArgumentException("Некорректный формат данных!");
            }
        }
    }
}
