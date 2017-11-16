	int count,next_chr;          
    bool flag_multi=false,flag_single=false;     
    while(EOF != (count=in.get()))  
    {
        if(count=='"' && (!flag_multi) && (!flag_single))   
        {
			while (count != '"')
			{
				out.put(count);                             
				count=in.get();   
			}
			out.put('"');                               
        }
        else if ((count == '\n') && (flag_single))        
        {
            flag_single = false;
            out.put('\n');                             
        }
        else if  (flag_multi == true && count == '*' && (next_chr=in.peek()) == '/')   
        {
            in.get();
            flag_multi = false;
                }
        else if (flag_single || flag_multi)      
            continue;
        else if (count == '/' && (next_chr=in.peek()) == '/')    
            flag_single = true;
        else if (count == '/' && (next_chr=in.peek()) == '*')    
            flag_multi = true;
        else                            
            out.put(count);
    }
    close_files(in,out);
