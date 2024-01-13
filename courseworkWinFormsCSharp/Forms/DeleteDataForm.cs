using System;
using System.Windows.Forms;
using courseworkWinFormsCSharp.DataManagers;
using courseworkWinFormsCSharp.OrderComponents;

namespace courseworkWinFormsCSharp.Forms
{
    public partial class DeleteDataForm : Form
    {
        public DeleteDataForm()
        {
            InitializeComponent();

            foreach (var item in OrdersData.GetPossibleIDs())
                PossibleIDsListBox.Items.Add(item);
        }

        private void CloseButton_Click(object sender, EventArgs e)
        {
            Close();
        }

        private void PossibleIDsListBox_SelectedIndexChanged(object sender, EventArgs e)
        {
            Order order = OrdersData.GetOrder((int)PossibleIDsListBox.SelectedItem);

            OrderDataGridView.Rows.Clear();
            OrderDataGridView.Rows.Add(order.ID, order.Laptop.ModelName, order.Status);
            
            LaptopDataGridView.Rows.Clear();
            LaptopDataGridView.Rows.Add
            (
                order.Laptop.ModelName, 
                order.Laptop.CPU, 
                order.Laptop.GPU, 
                order.Laptop.RAM, 
                order.Laptop.Motherboard, 
                order.Laptop.Display, 
                order.Laptop.DataStorage
            );

            DeleteDataButton.Enabled = true;
        }

        private void DeleteDataButton_Click(object sender, EventArgs e)
        {
            if (MessageBox.Show("Вы уверены, что хотите удалить запись?", "Удалить запись", MessageBoxButtons.YesNo, MessageBoxIcon.Question) == DialogResult.Yes)
            {
                OrdersData.RemoveOrder((int)PossibleIDsListBox.SelectedItem);
                Close();
            }
        }
    }
}
