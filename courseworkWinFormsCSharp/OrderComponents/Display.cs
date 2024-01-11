using Newtonsoft.Json.Linq;
using System;

namespace courseworkWinFormsCSharp.OrderComponents
{
    public class Display : ILaptopComponent
    {
        private int _width;
        public int Width
        {
            get => _width;
            set
            {
                if (value >= 0)
                    _width = value;
                else
                    throw new ArgumentException("Некорректная ширина экрана!");
            }
        }
        private int _height;
        public int Height
        {
            get => _height;
            set
            {
                if (value >= 0)
                    _height = value;
                else
                    throw new ArgumentException("Некорректная высота экрана!");
            }
        }
        private int _refreshRate;
        public int RefreshRate
        {
            get => _refreshRate;
            set
            {
                if (value >= 0)
                    _refreshRate = value;
                else
                    throw new ArgumentException("Некорректная частота обновления экрана!");
            }
        }

        public Display() { }
        public Display(int Width, int Height)
        {
            this.Width = Width;
            this.Height = Height;
        }

        public Display(int Width, int Height, int RefreshRate)
        {
            this.Width = Width;
            this.Height = Height;
            this.RefreshRate = RefreshRate;
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
            Width = display.GetValue("width").ToObject<int>();
            Height = display.GetValue("height").ToObject<int>();
            RefreshRate = display.GetValue("refreshRate").ToObject<int>();
        }
    }
}
