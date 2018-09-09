#include "Data.h"


void Date::Print_Date()
{
    cout << this->_year << "-" << this->_month << "-" << this->_day << endl;

}
int Date::GetMonthDay(int year, int month)
{
    int MonthDay[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    if (((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) && month == 2)
    {
        return MonthDay[month] + 1;   //解决闰年2月问题
    }
    else
    {
        return MonthDay[month];
    }
}
bool Date::CheckLegality()
{
    if ((this->_month>0 && this->_month <= 12)
            && this->_day>0 && this->_day <= GetMonthDay(this->_year, this->_month)
       )
        return true;
    else
        return false;

}



//日期加上一个天数
//加一个正数
//加一个负数	转至减一个数
//加0       直接返回
Date& Date:: operator+=(int day)
{
    //1给日期加上这个天数
    //2每次减去当前月的天数，月数进1，再检查月是否满，给年进一，直到天数合法
    if (day<0)
    {
        day = -day;
        operator-=(day);
    }
    else
    {
        this->_day += day;
        while (CheckLegality() == 0)
        {
            this->_day -= GetMonthDay(this->_year, this->_month);
            this->_month += 1;
            if (this->_month > 12)
            {
                this->_year += 1;
                this->_month -= 12;
            }
        }
    }
    return *this;
}
//减去一个正数
//减去一个负数  转致加一个数
//减去0		  直接返回
Date& Date:: operator-=(int day)
{
    //1先加上这个负数
    //2每次加上前一个月的天数，然后月数减一，再检查月数是否合法，考虑给年减一，直到日期合法

    if (day<0)             //如果day为负数，减去一个负数等于加上一个正数，调用operator+
    {
        day = -day;
        operator+=(day);
    }
    else
    {
        this->_day -= day;
        while (CheckLegality() == 0)
        {
            if (this->_month == 1)    //解决1月-1 得到0月   0月返回0天问题
            {
                this->_day += 31;
                this->_year -= 1;
                this->_month = 12;
            }
            else
            {
                this->_day += GetMonthDay(this->_year, (this->_month) - 1);
                this->_month -= 1;
            }
        }
    }
    return *this;
}
//>重载
bool Date:: operator>(const Date& d)
{
    if (this->_year > d._year)
    {
        return true;
    }
    else if (this->_year < d._year)
    {
        return false;
    }
    else
    {
        if (this->_month > d._month)
        {
            return true;
        }
        else if (this->_month < d._month)
        {
            return false;
        }
        else
        {
            if (this->_day > d._day)
            {
                return true;
            }
            else if (this->_day < d._day)
            {
                return false;
            }
            else
                return false;
        }
    }
}
bool Date:: operator==(const Date& d)
{
    if (this->_year == d._year
            &&this->_month == d._month
            &&this->_day == d._day)
        return true;
    else
        return false;
}

Date& Date:: operator++()
{
    this->_day += 1;
    if (CheckLegality() == 0)
    {
        this->_day -= GetMonthDay(this->_year, this->_month);
        this->_month += 1;
        if (CheckLegality() == 0)
        {
            this->_month = 1;
            this->_year += 1;
        }
    }
    return *this;
}

//先判断哪个日期大哪个日期小
//用小的日期不断++ 逼近较大的日期直到相等
int Date:: operator-(const Date& d)
{
    Date big;
    Date small;
    int count = 0;
    if (operator>(d))
    {
        big = *this;
        small = d;
    }
    else
    {
        big = d;
        small = *this;
    }
    while (!(small.operator==(big)))
    {
        small.operator++();
        count++;
    }
    return count;
}


void data_three(char* buf)
{
    //printf("hello world");

    strtok(buf,"=&");
    int year,month,day;
    int newyear,newmonth,newday;
    year = atoi(strtok(NULL,"=&"));
    strtok(NULL,"=&");
    month = atoi(strtok(NULL,"=&"));
    strtok(NULL,"=&");
    day = atoi(strtok(NULL,"=&"));
    strtok(NULL,"=&");
    newyear = atoi(strtok(NULL,"=&"));
    strtok(NULL,"=&");
    newmonth = atoi(strtok(NULL,"=&"));
    strtok(NULL,"=&");
    newday = atoi(strtok(NULL,"=&"));
    // scannf(buf,"year = %d-month=%d-day=%d",&x,&y);
    //sscanf(buf,"year=%dmonth=%dday=%dyear=%dmonth=%dday=%d\n",&year,&month,&day,&newyear,&newmonth,&newday);
    Date d1(year,month,day);
    Date d2(newyear,newmonth,newday);
    int count = 0;
    count = d1-d2;
    printf("<html>\n");
    printf("<meta charset='UTF-8'");
    printf("<h3>%d/%d/%dand%d/%d/%ddel: %dday</h3>\n",d1._year,d1._month,d1._day,d2._year,d2._month,d2._day,count);
    printf("</html>\n");
}   //
void data_one(char* buf)
{
    //i//``nt year,month,day;
    //i//``nt newday;
    //s//``scanf(buf,"%d%d%d%d",&year,&month,&day,&newday);
    //D//``ate d1(year,month,day);
    //d//``1 -= newday;
    //p//``rintf("<html>\n");
    //p//``rintf("<meta charset='UTF-8'");
    //p//``rintf("<h1>result is：%d/%d/%d</h1>\n",d1._year,d1._month,d1._day);
    //p//``rintf("</html>\n");

}
int main()
{
    Date date(1997, 8, 31);
    char method[64];
    char buf[1024];
    int content_length = -1;
    if(getenv("METHOD"))
    {
        strcpy(method,getenv("METHOD"));

        if( strcasecmp(method,"GET")==0)
        {
            strcpy(buf,getenv("QUERY_STRING"));
        }
        else
        {
            content_length = atoi(getenv("CONTENT_LENGTH"));
            int i =0;
            for(;i<content_length;i++)
            {
                read(0,buf+i,1);
            }
            buf[i]='\0';
        }
    }
        data_three(buf);
        printf("http");
    return 0;
}


