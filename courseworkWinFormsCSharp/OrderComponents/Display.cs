using Newtonsoft.Json.Linq;
using System;

namespace courseworkWinFormsCSharp.OrderComponents
{
    public class Display : ILaptopComponent
    {
        public int Width
        {
            get => Width;
            set => TryToSetArguments(value, Height, RefreshRate);
        }
        public int Height
        {
            get => Height;
            set => TryToSetArguments(Width, value, RefreshRate);
        }
        public int RefreshRate
        {
            get => RefreshRate;
            set => TryToSetArguments(Width, Height, value);
        }

        public Display(int width, int height)
        {
            TryToSetArguments(width, height, 0);
        }

        public Display(int width, int height, int refreshRate)
        {
            TryToSetArguments(width, height, refreshRate);
        }
        public Display(JObject json)
        {
            FromJSON(json);
        }
        public string GetComponentName() => "Display";

        public override string ToString()
        {
            return $"{Width}x{Height}, {RefreshRate} Гц";
        }

        public JObject ToJSON()
        {
            JObject display = new JObject
            {
                { "width", Width },
                { "height", Height },
                { "refreshRate", RefreshRate }
            };
            return display;
        }

        public void FromJSON(JObject display)
        {
            TryToSetArguments(display.GetValue("width").ToObject<int>(), display.GetValue("height").ToObject<int>(), display.GetValue("refreshRate").ToObject<int>());
        }

        private bool CheckArguments(int Width, int Height, int RefreshRate)
        {
            return Width >= 0 && Height >= 0 && RefreshRate >= 0;
        }

        private void TryToSetArguments(int Width, int Height, int RefreshRate)
        {
            if (CheckArguments(Width, Height, RefreshRate))
            {
                this.Width = Width;
                this.Height = Height;
                this.RefreshRate = RefreshRate;
            }
            else
            {
                throw new ArgumentException("Некорректный формат данных!");
            }
        }
    }
}
