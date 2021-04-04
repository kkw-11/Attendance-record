//Attendance record
//Raspberry Server

#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<string.h>
#include <mariadb/mysql.h>

#include<wiringPi.h>
#include<wiringSerial.h>

static char *host = "localhost";
static char *user = "root";
static char *pass = "KCCI";
static char *dbname = "test";

char device [] = "/dev/ttyACM0"; // usb port
int fd, str_len;
unsigned long baud = 9600;  // serial communication

int main(){

        MYSQL *conn;
        int res;
        char in_sql[200] = {0};
        char name[10] = { 0 };
        int nameindex = 0;
        int flag = 0;

        conn = mysql_init(NULL);

        printf("Raspberry Start\n");
        fflush(stdout);

        if ((fd = serialOpen(device, baud)) < 0 )
                exit(1);
        if(wiringPiSetupGpio() == -1)
                return -1;
        if(!(mysql_real_connect(conn, host, user, pass, dbname, 0, NULL,0)))
        {
                fprintf(stderr, "error : %s[%d] \n", mysql_error(conn), mysql_errno(conn));
                exit(1);
        }
        else
                printf("SQL CONNECTION\n");

        while(1){
                if(serialDataAvail(fd)){
                        name[nameindex++] = serialGetchar(fd);
                        if(name[nameindex - 1] == '.')
                        {
                                flag = 1;
                                name[nameindex - 1 ] = '\0';
                                str_len = strlen(name);
                                printf("test name = %s nameindex = %d, strlen = %d\n", name, nameindex, str_len);
                        }

                        if(flag == 1)
                        {
                                sprintf(in_sql, "insert into attend(id, name, time) values(null, '%s', now())",name);
                        res = mysql_query(conn, in_sql);
                        for (int i = 0; i <= str_len; i++)
                                name[i] = 0;
                        nameindex = 0;
                        if(!res)
                                printf("inserted %lu rows \n", (unsigned long)mysql_affected_rows(conn));
                        else
                                fprintf(stderr, "error : %s[%d] \n", mysql_error(conn), mysql_errno(conn));
                        flag = 0;
                        }
                }
        }

        mysql_close(conn);
        return EXIT_SUCCESS;
}
