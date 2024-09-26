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

    public string ReadFromFile(string lpfilename)
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

        return str;
    }
    
}



