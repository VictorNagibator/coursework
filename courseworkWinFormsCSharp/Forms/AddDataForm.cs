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
    }
}
