using courseworkWinFormsCSharp.DataManagers;
using courseworkWinFormsCSharp.OrderComponents;
using System;
using System.Windows.Forms;

namespace courseworkWinFormsCSharp.Forms
{
    public partial class AddDataForm : Form
    {
        public AddDataForm()
        {
            InitializeComponent();

            IDTextBox.Text = (Order.LastID + 1).ToString();
        }

        private void CloseButton_Click(object sender, EventArgs e)
        {
            Close();
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

        private void AddDataButton_Click(object sender, EventArgs e)
        {
            try
            {
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
                else if(ChooseDataStorageListBox.SelectedItem.ToString() == "SSD")
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

                OrdersData.AddOrder(new Order(laptop, StatusTypeConverter.StringToStatusType(StatusListBox.SelectedItem.ToString()), AdditionalInfoTextBox.Text));

                MessageBox.Show("Заказ успешно добавлен!", "Успех", MessageBoxButtons.OK, MessageBoxIcon.Information);
                Close();
            }
            catch (Exception exception)
            {
                MessageBox.Show(exception.Message, "Ошибка", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
        }
    }
}
