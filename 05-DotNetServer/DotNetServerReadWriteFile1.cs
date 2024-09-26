using System;
using System.IO;

public class DotNetServerReadWriteFile
{
    

	public void WriteToFile(string Name,string DOB,string Address,string Education,string Company,string lpfilename)
    {
        
        using(StreamWriter OutputFile = new StreamWriter(lpfilename,true))
        {
            OutputFile.WriteLine(Name);
            OutputFile.WriteLine(DOB);
            OutputFile.WriteLine(Address);
            OutputFile.WriteLine(Education);
            OutputFile.WriteLine(Company);


            OutputFile.Close();
        }
    }

    public void ReadFromFile(string lpfilename,string lpfilename2)
    {
        string str="";
        using(StreamReader InputFile = new StreamReader(lpfilename))
        {
            int counter = 0;
            string line;
            int i = 0;

            while((line=InputFile.ReadLine())!=null)
            {
                if(counter>=13 && i<5)
                {
                    str = str + line+"\n";
                    i++;
                }

                counter++;
            }

            InputFile.Close();
        }

        using (StreamWriter abc = new StreamWriter(lpfilename2))
        {
            abc.WriteLine("hihi");
            abc.WriteLine(str);
            // OutputFile.WriteLine(DOB);
            //OutputFile.WriteLine(Address);
            //OutputFile.WriteLine(Education);
            //OutputFile.WriteLine(Company);


            abc.Close();
        }

        
    }

}



