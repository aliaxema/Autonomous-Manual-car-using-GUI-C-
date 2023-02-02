using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.IO.Ports;

namespace WindowsFormsApp2
{
    public partial class Form1 : Form
    {
        SerialPort port = null;
        string distanse;
        string dataRX = " ";
        delegate void serialCalback(string val);
        public Form1()
        {
            InitializeComponent();
            refreshCom();
            label1.Text = "Disconnected";
            label1.ForeColor = Color.Red;
        }

        private void button1_Click(object sender, EventArgs e)
        {
            Connect();
        }

        private void button2_Click(object sender, EventArgs e)
        {
            Disconnect();
        }

        private void button3_Click(object sender, EventArgs e)
        {
            refreshCom();
        }
        private void refreshCom()
        {
            comboBox1.DataSource = SerialPort.GetPortNames();
        }
        private void Connect()
        {
            port = new SerialPort(comboBox1.SelectedItem.ToString());
            port.BaudRate = 9600;
            port.DataBits = 8;
            port.StopBits = StopBits.One;
            try
            {
                if (!port.IsOpen)
                {
                    port.Open();
                    label1.Text = "Connected";
                    label1.ForeColor = Color.Green;
                        }
            }catch(Exception ex) {
                MessageBox.Show(ex.Message);
            }
            port.DataReceived += new System.IO.Ports.SerialDataReceivedEventHandler(DataReceived);


        }
        private void Disconnect()
        {
            try
            {
                if (port.IsOpen)
                {
                    port.Close();
                    label1.Text = "Disconnected";
                    label1.ForeColor = Color.Red;
                }
            }catch(Exception ex)
            {

            }
        }

        private void Form1_FormClosed(object sender, FormClosedEventArgs e)
        {
            Disconnect();
        }

       

        /*private void trackBar1_Scroll(object sender, EventArgs e)
        {
            label2.Text =  trackBar1.Value.ToString();
           
        }
        */
      
        /*private void trackBar1_MouseLeave(object sender, EventArgs e)
        {
            try
            {
                port.Write(trackBar1.Value.ToString());
            }catch(Exception ex) { }
        }*/

        private void button8_Click(object sender, EventArgs e)
        {

            try
            {
                port.Write("A");
            }
            catch (Exception ex) { }
        }

        private void label2_Click(object sender, EventArgs e)
        {

        }

        private void button9_Click(object sender, EventArgs e)
        {

            try
            {
                port.Write("M");
            }
            catch (Exception ex) { }

        }

        private void button10_Click(object sender, EventArgs e)
        {
            try
            {
                port.Write("S");
            }
            catch
            (Exception ex)
            {
                MessageBox.Show(ex.Message);
            }
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            String[] ports = SerialPort.GetPortNames();

         }

        private void up()
        {
            try
            {
                port.Write("2");
            }
            catch
            (Exception ex)
            {
                MessageBox.Show(ex.Message);
            }
        }
        private void back()
        {
            try
            {
                port.Write("4");
            }
            catch
            (Exception ex)
            {
                MessageBox.Show(ex.Message);
            }
        }
        private void right()
        {
            try
            {
               
                port.Write("6");
            }
            catch
            (Exception ex)
            {
                MessageBox.Show(ex.Message);
            }
        }
        private void left()
        {
            try
            {
                port.Write("8");
            }
            catch
            (Exception ex)
            {
                MessageBox.Show(ex.Message);
            }
        }
        private void button4_Click(object sender, EventArgs e)
        {
            up();
        }

        private void button7_Click(object sender, EventArgs e)
        {
            left();

        }

        private void button6_Click(object sender, EventArgs e)
        {
            back();
        }

        private void button5_Click(object sender, EventArgs e)
        {
            right();
        }

       
        private void button11_Click(object sender, EventArgs e)
        {
            DIStance();
            textBox1.Text = dataRX;
            

        }

        private void button12_Click(object sender, EventArgs e)
        {
            right();
        }

        private void DataReceived(object sender, SerialDataReceivedEventArgs e)
        {
            try
            {
                SerialPort sp = (SerialPort)sender;
                string temp = sp.ReadExisting();
                //setText(temp);
                dataRX += temp;
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message);
                 
            }
        }
       /* private void setText(string val)
        {
            if (this.textBox1.InvokeRequired)
            {
                serialCalback scb = new serialCalback(setText);
                this.Invoke(scb, new object[] { val });

            }
            else
            {
                distanse = val;

            }
        }*/
        private void distance()
        {
            try
            {
                port.Write("D");
                // distanse = port.ReadExisting();
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message);
            }
        }
        private void DIStance()
        {
            try
            {
                port.Write("D");
            }
            catch
            (Exception ex)
            {
                MessageBox.Show(ex.Message);
            }
        }
        private void button13_Click(object sender, EventArgs e)
        {
            textBox1.Clear();
            dataRX = " ";
        }

        private void textBox1_TextChanged(object sender, EventArgs e)
        {

        }
    }
    }
    

