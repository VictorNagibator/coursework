using Newtonsoft.Json.Linq;
using System;

namespace courseworkWinFormsCSharp.OrderComponents
{
    public class Laptop
    {
        public string ModelName { get; set; } = string.Empty;
        private CPU _cpu = new CPU();
        public CPU CPU
        {
            get => _cpu;
            set
            {
                if (value.Socket == Motherboard.Socket)
                    _cpu = value;
                else
                    throw new ArgumentException("Неподходящий сокет CPU к данной материнской плате!");
            }
        }
        public GPU GPU { get; set; } = new GPU();
        private RAM _ram = new RAM();
        public RAM RAM
        {
            get => _ram;
            set
            {
                if (value.Type == Motherboard.SupportedRAMType)
                    _ram = value;
                else
                    throw new ArgumentException("Неподходящий тип оперативной памяти к данной материнской плате!");
            }
        }
        public Motherboard Motherboard { get; set; } = new Motherboard();
        public Display Display { get; set; } = new Display();
        public DataStorage DataStorage { get; set; } = new HDD(); //по умолчанию стоит HDD в ноутбуках

        public Laptop() { }
        public Laptop(string ModelName, CPU CPU, GPU GPU, RAM RAM, Motherboard Motherboard, Display Display, DataStorage DataStorage)
        {
            this.Motherboard = Motherboard; //сначала устанавливаем материнскую плату

            this.ModelName = ModelName;
            this.CPU = CPU;
            this.GPU = GPU;
            this.RAM = RAM;
            this.Display = Display;
            this.DataStorage = DataStorage;
        }


        public void BoostCPU()
        {
            CPU++;
        }

        public void BoostCPU(float Addable)
        {
            CPU += Addable;
        }

        public void BoostRAM()
        {
            RAM++;
        }

        public void BoostRAM(float addable)
        {
            RAM += addable;
        }

        public override string ToString()
        {
            return $"Название модели: {ModelName}\n" +
                   $"CPU: {CPU}\n" +
                   $"GPU: {GPU}\n" +
                   $"RAM: {RAM}\n" +
                   $"Материнская плата: {Motherboard}\n" +
                   $"Экран: {Display}\n" +
                   $"{DataStorage.GetComponentName()}: {DataStorage}\n";
        }

        public JObject ToJSON()
        {
            JObject json = new JObject
            {
                { "modelName", ModelName },
                { "cpu", CPU.ToJSON() },
                { "gpu", GPU.ToJSON() },
                { "ram", RAM.ToJSON() },
                { "motherboard", Motherboard.ToJSON() },
                { "display", Display.ToJSON() },
                { "dataStorage", DataStorage.ToJSON() }
            };
            return json;
        }

        public void FromJSON(JObject json)
        {
            Motherboard = new Motherboard(json.GetValue("motherboard").ToObject<JObject>());

            DataStorage dataStorage;
            if (json.GetValue("dataStorage").ToObject<JObject>().GetValue("componentName").ToString() == "HDD")
            {
                dataStorage = new HDD(json.GetValue("dataStorage").ToObject<JObject>());
            }   
            else
            {
                dataStorage = new SSD(json.GetValue("dataStorage").ToObject<JObject>());
            }

            ModelName = json.GetValue("modelName").ToString();
            CPU = new CPU(json.GetValue("cpu").ToObject<JObject>());
            GPU = new GPU(json.GetValue("gpu").ToObject<JObject>());
            RAM = new RAM(json.GetValue("ram").ToObject<JObject>());
            Display = new Display(json.GetValue("display").ToObject<JObject>());
            DataStorage = dataStorage;
        }
    }
}
