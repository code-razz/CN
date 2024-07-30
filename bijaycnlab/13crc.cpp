#include <iostream>
#include <string.h>
using namespace std;

int crc(char *ip, char *op, char *poly, int mode)
{
    strcpy(op, ip);
    if (mode) {
        for (int i = 1; i < strlen(poly); i++)
            strcat(op, "0");
    }
    /* Perform XOR on the msg with the selected polynomial */
    for (int i = 0; i < strlen(ip); i++) {
        if (op[i] == '1') {
            for (int j = 0; j < strlen(poly); j++) {
                if (op[i + j] == poly[j])
                    op[i + j] = '0';
                else
                    op[i + j] = '1';
            }
        }
    }
    /* check for errors. return 0 if error detected */
    for (int i = 0; i < strlen(op); i++)
        if (op[i] == '1')
            return 0;
    return 1;
}

int main()
{
    char ip[50], op[50], recv[50];
    char poly[] = "10001000000100001";

    cout << "enter the input message in binary:\n";
    cin >> ip;

    crc(ip, op, poly, 1);
    cout << "the transmitted message is: " << ip << op + strlen(ip) << endl;

    cout << "enter the received message: \n"
         << endl;
    cin >> recv;

    if (crc(recv, op, poly, 0))
    {
        cout << "no error detected: " << endl;
    }
    else
    {
        cout << "error in data" << endl;
    }

    return 0;
}