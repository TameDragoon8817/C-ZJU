int set_grade( struct student *p, int n )  
{  
    int count=0,i;  
    
    for(i=0;i<n;i++)  
    {  
        if((*p).score<60)
        {  
            (*p).grade='D';  
            count++;  
        }  
        else if((*p).score>=60&&(*p).score<=69)  
        (*p).grade='C';  
        else if((*p).score>=70&&(*p).score<=84)  
        (*p).grade='B';  
        else  
        (*p).grade='A';  
        
		p++;
    }  
      
    return count;
}