using System;
using System.Collections.Generic;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Diagnostics;

namespace photonTest
{
    static class Program
    {     
        [STAThread]
        static void Main() {
            Application.EnableVisualStyles();
            Application.SetCompatibleTextRenderingDefault(false);
            //Application.Run(new Form1());
            // cmd.StandardInput.WriteLine("particle login");
            //cmd.StartInfo.Arguments = "robotican.photon@gmail.com r1234567";
           
                List<string> photonsNames = new List<string>(2);

                for (int i = 1; i <= 2; i++)
                    photonsNames.Add("photon" + i);

                #region ParallelTasks              
                Parallel.ForEach(photonsNames, photonName =>
                {
                    flashPhoton(photonName);
                });   
          
            #endregion               
            //MessageBox.Show(output);
        }
        public static void flashPhoton(String photonName)
        {
            
            Process cmd = new Process();
            cmd.StartInfo.FileName = "cmd.exe";
            cmd.StartInfo.RedirectStandardInput = true;
            cmd.StartInfo.RedirectStandardOutput = true;
            cmd.StartInfo.RedirectStandardError = true;
            cmd.StartInfo.CreateNoWindow = true;
            cmd.StartInfo.UseShellExecute = false;       

            cmd.Start();
            
            cmd.StandardInput.WriteLine(@"cd C:\");
            cmd.StandardInput.WriteLine("particle flash " + photonName + " firmware.bin");  
            cmd.StandardInput.Flush();  
            cmd.StandardInput.Close();
            
            cmd.BeginOutputReadLine();
            cmd.BeginErrorReadLine();
            cmd.WaitForExit();
           // string output = cmd.StandardOutput.ReadToEnd();
          //  Console.WriteLine("hello" + output);

        }
    }    
}
   