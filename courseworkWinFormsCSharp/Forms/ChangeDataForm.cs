using courseworkWinFormsCSharp.DataManagers;
using courseworkWinFormsCSharp.OrderComponents;
using System;
using System.Windows.Forms;

namespace courseworkWinFormsCSharp.Forms
{
    public partial class ChangeDataForm : Form
    {
        public ChangeDataForm()
        {
            InitializeComponent();

            foreach (var item in OrdersData.GetPossibleIDs())
                PossibleIDsListBox.Items.Add(item);
        }

        private void PossibleIDsListBox_SelectedIndexChanged(object sender, EventArgs e)
        {
            Order changableOrder = OrdersData.GetOrder((int)PossibleIDsListBox.SelectedItem);

            StatusListBox.SelectedItem = StatusTypeConverter.StatusTypeToString(changableOrder.Status);
            AdditionalInfoTextBox.Text = changableOrder.AdditionalInfo;
            LaptopModelTextbox.Text = changableOrder.Laptop.ModelName;

            CPUModelTextBox.Text = changableOrder.Laptop.CPU.ModelName;
            CPUSocketTextBox.Text = changableOrder.Laptop.CPU.Socket;
            CPUCoresNumericUpDown.Value = changableOrder.Laptop.CPU.NumOfCores;
            CPUFrequencyNumericUpDown.Value = (decimal)changableOrder.Laptop.CPU.Frequency;

            GPUModelTextBox.Text = changableOrder.Laptop.GPU.ModelName;
            GPUFrequencyNumericUpDown.Value = (decimal)changableOrder.Laptop.GPU.Frequency;
            GPUVRAMNumericUpDown.Value = changableOrder.Laptop.GPU.VRAM;

            RAMModelTextBox.Text = changableOrder.Laptop.RAM.ModelName;
            RAMFrequencyNumericUpDown.Value = (decimal)changableOrder.Laptop.RAM.Frequency;
            RAMCapacityNumericUpDown.Value = changableOrder.Laptop.RAM.Capacity;
            RAMTypeListBox.SelectedItem = changableOrder.Laptop.RAM.Type.ToString();

            DisplayFrequencyNumericUpDown.Value = changableOrder.Laptop.Display.RefreshRate;
            DisplayHeightNumericUpDown.Value = changableOrder.Laptop.Display.Height;
            DisplayWidthNumericUpDown.Value = changableOrder.Laptop.Display.Width;

            MotherboardChipsetTextBox.Text = changableOrder.Laptop.Motherboard.Chipset;
            MotherboardSocketTextBox.Text = changableOrder.Laptop.Motherboard.Socket;
            MotherboardModelTextBox.Text = changableOrder.Laptop.Motherboard.ModelName;
            MotherboardRAMTypeListBox.SelectedItem = changableOrder.Laptop.Motherboard.SupportedRAMType.ToString();

            ChooseDataStorageListBox.SelectedItem = changableOrder.Laptop.DataStorage.GetComponentName();
            DataStorageCapacityNumericUpDown.Value = changableOrder.Laptop.DataStorage.Capacity;
            DataStorageBrandTextBox.Text = changableOrder.Laptop.DataStorage.Brand;
            DataStorageFormFactorNumericUpDown.Value = (decimal)changableOrder.Laptop.DataStorage.FormFactor;
            DataStorageInterfaceTypeListBox.SelectedItem = changableOrder.Laptop.DataStorage.TransferInterface.ToString();

            if (changableOrder.Laptop.DataStorage is HDD hdd)
            {
                DataStorageSpindleSpeedNumericUpDown.Value = hdd.SpindleSpeed;
            }
            else if (changableOrder.Laptop.DataStorage is SSD ssd)
            {
                DataStorageFlashMemoryTypeListBox.SelectedItem = ssd.TypeOfFlashMemory.ToString();
            }
        }

        private void ChangeDataButton_Click(object sender, System.EventArgs e)
        {
            try
            {
                Order changableOrder = OrdersData.GetOrder((int)PossibleIDsListBox.SelectedItem);

                DataStorage dataStorage;
                if (ChooseDataStorageListBox.SelectedItem.ToString() == "HDD")
                {
                    dataStorage = new HDD
                    (
                        (int)DataStorageCapacityNumericUpDown.Value,
                        DataTransferInterfaceConverter.StringToDataTransferInterface(DataStorageInterfaceTypeListBox.SelectedItem.ToString()),
                        DataStorageBrandTextBox.Text,
                        (float)DataStorageFormFactorNumericUpDown.Value,
                        (int)DataStorageSpindleSpeedNumericUpDown.Value
                    );
                }
                else if (ChooseDataStorageListBox.SelectedItem.ToString() == "SSD")
                {
                    dataStorage = new SSD
                    (
                        (int)DataStorageCapacityNumericUpDown.Value,
                        DataTransferInterfaceConverter.StringToDataTransferInterface(DataStorageInterfaceTypeListBox.SelectedItem.ToString()),
                        DataStorageBrandTextBox.Text,
                        (float)DataStorageFormFactorNumericUpDown.Value,
                        FlashMemoryTypeConverter.StringToFlashMemoryType(DataStorageFlashMemoryTypeListBox.SelectedItem.ToString())
                    );
                }
                else
                {
                    throw new Exception("Не выбран тип хранилища!");
                }

                Laptop laptop = new Laptop
                (
                    LaptopModelTextbox.Text,
                    new CPU
                    (
                        CPUModelTextBox.Text,
                        CPUSocketTextBox.Text,
                        (float)CPUFrequencyNumericUpDown.Value,
                        (int)CPUCoresNumericUpDown.Value
                    ),
                    new GPU
                    (
                        GPUModelTextBox.Text,
                        (float)GPUFrequencyNumericUpDown.Value,
                        (int)GPUVRAMNumericUpDown.Value
                    ),
                    new RAM
                    (
                       RAMModelTextBox.Text,
                       RAMTypeConverter.StringToRAMType(RAMTypeListBox.SelectedItem.ToString()),
                       (float)RAMFrequencyNumericUpDown.Value,
                       (int)RAMCapacityNumericUpDown.Value
                    ),
                    new Motherboard
                    (
                       MotherboardModelTextBox.Text,
                       MotherboardSocketTextBox.Text,
                       MotherboardChipsetTextBox.Text,
                       RAMTypeConverter.StringToRAMType(RAMTypeListBox.SelectedItem.ToString())
                    ),
                    new Display
                    (
                        (int)DisplayWidthNumericUpDown.Value,
                        (int)DisplayHeightNumericUpDown.Value,
                        (int)DisplayFrequencyNumericUpDown.Value
                    ),
                    dataStorage
                );

                changableOrder.Status = StatusTypeConverter.StringToStatusType(StatusListBox.SelectedItem.ToString());
                changableOrder.AdditionalInfo = AdditionalInfoTextBox.Text;
                changableOrder.Laptop = laptop;

                OrdersData.EditOrder(changableOrder);

                MessageBox.Show("Заказ успешно изменен!", "Успех", MessageBoxButtons.OK, MessageBoxIcon.Information);
                Close();
            }
            catch (System.Exception exception)
            {
                MessageBox.Show(exception.Message, "Ошибка", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
        }

        private void ChooseDataStorageListBox_SelectedIndexChanged(object sender, EventArgs e)
        {
            switch (ChooseDataStorageListBox.SelectedItem)
            {
                case "HDD":
                    DataStorageSpindleSpeedLabel.Visible = true;
                    DataStorageSpindleSpeedNumericUpDown.Visible = true;
                    DataStorageFlashMemoryTypeLabel.Visible = false;
                    DataStorageFlashMemoryTypeListBox.Visible = false;

                    break;
                case "SSD":
                    DataStorageSpindleSpeedLabel.Visible = false;
                    DataStorageSpindleSpeedNumericUpDown.Visible = false;
                    DataStorageFlashMemoryTypeLabel.Visible = true;
                    DataStorageFlashMemoryTypeListBox.Visible = true;

                    break;
            }
        }
    }
}
