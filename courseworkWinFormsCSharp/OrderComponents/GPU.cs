using Newtonsoft.Json.Linq;
using System;

namespace courseworkWinFormsCSharp.OrderComponents
{
    public class GPU : ILaptopComponent
    {
        public string ModelName { get; set; } = string.Empty;
        private float _frequency;
        public float Frequency
        {
            get => _frequency;
            set
            {
                if (value >= 0)
                    _frequency = value;
                else
                    throw new ArgumentException("Некорректная частота GPU!");
            }
        }
        private int _vram;
        public int VRAM
        {
            get => _vram;
            set
            {
                if (value >= 0)
                    _vram = value;
                else
                    throw new ArgumentException("Некорректный объем памяти GPU!");
            }
        }

        public GPU()
        {
            
        }

        public GPU(string ModelName)
        {
            this.ModelName = ModelName;
        }

        public GPU(string ModelName, float Frequency, int VRAM)
        {
            this.ModelName = ModelName;
            this.Frequency = Frequency;
            this.VRAM = VRAM;
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
            ModelName = gpu.GetValue("modelName").ToString();
            Frequency = gpu.GetValue("frequency").ToObject<float>();
            VRAM = gpu.GetValue("vram").ToObject<int>();
        }
    }
}
