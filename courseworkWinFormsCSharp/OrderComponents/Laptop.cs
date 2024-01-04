using Newtonsoft.Json.Linq;
using System.Net.Configuration;

namespace courseworkWinFormsCSharp.OrderComponents
{
    public class Laptop
    {
        public string ModelName
        {
            get => ModelName;
            set => TryToSetArguments(value, CPU, GPU, RAM, Motherboard, Display, DataStorage);
        }
        public CPU CPU
        {
            get => CPU;
            set => TryToSetArguments(ModelName, value, GPU, RAM, Motherboard, Display, DataStorage);
        }
        public GPU GPU
        {
            get => GPU;
            set => TryToSetArguments(ModelName, CPU, value, RAM, Motherboard, Display, DataStorage);
        }
        public RAM RAM
        {
            get => RAM;
            set => TryToSetArguments(ModelName, CPU, GPU, value, Motherboard, Display, DataStorage);
        }
        public Motherboard Motherboard
        {
            get => Motherboard;
            set => TryToSetArguments(ModelName, CPU, GPU, RAM, value, Display, DataStorage);
        }
        public Display Display
        {
            get => Display;
            set => TryToSetArguments(ModelName, CPU, GPU, RAM, Motherboard, value, DataStorage);
        }
        public DataStorage DataStorage
        {
            get => DataStorage;
            set => TryToSetArguments(ModelName, CPU, GPU, RAM, Motherboard, Display, value);
        }

        public Laptop(string ModelName, CPU CPU, GPU GPU, RAM RAM, Motherboard Motherboard, Display Display, DataStorage DataStorage)
        {
            TryToSetArguments(ModelName, CPU, GPU, RAM, Motherboard, Display, DataStorage);
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
            DataStorage dataStorage;
            if (json.GetValue("dataStorage").ToObject<JObject>().GetValue("componentName").ToString() == "HDD")
            {
                dataStorage = new HDD(json.GetValue("dataStorage").ToObject<JObject>());
            }   
            else
            {
                dataStorage = new SSD(json.GetValue("dataStorage").ToObject<JObject>());
            }    

            TryToSetArguments
            (
                json.GetValue("modelName").ToString(), 
                new CPU(json.GetValue("cpu").ToObject<JObject>()), 
                new GPU(json.GetValue("gpu").ToObject<JObject>()), 
                new RAM(json.GetValue("ram").ToObject<JObject>()),
                new Motherboard(json.GetValue("motherboard").ToObject<JObject>()),
                new Display(json.GetValue("display").ToObject<JObject>()),
                dataStorage
            );
        }

        private bool CheckArguments(string ModelName, CPU CPU, GPU GPU, RAM RAM, Motherboard Motherboard, Display Display, DataStorage DataStorage)
        {
            return CPU.Socket == Motherboard.Socket && RAM.Type == Motherboard.SupportedRAMType;
        }

        private void TryToSetArguments(string ModelName, CPU CPU, GPU GPU, RAM RAM, Motherboard Motherboard, Display Display, DataStorage DataStorage)
        {
            if (CheckArguments(ModelName, CPU, GPU, RAM, Motherboard, Display, DataStorage))
            {
                this.ModelName = ModelName;
                this.CPU = CPU;
                this.GPU = GPU;
                this.RAM = RAM;
                this.Motherboard = Motherboard;
                this.Display = Display;
                this.DataStorage = DataStorage;
            }
        }
    }
}
