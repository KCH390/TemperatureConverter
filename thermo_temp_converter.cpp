#include <iostream>
#include <cctype>

using std::cout;
using std::cin;
using std::endl;

double K2R(double K){
    return K*1.8;
}
double R2K(double R){
    return R/1.8;
}
double F2C(double F){
    return (F-32)/1.8;
}
double C2F(double C){
    return C*1.8+32;
}
double C2K(double C){
    return C+273.15;
}
double K2C(double K){
    return K-273.15;
}

int main() {
    char temp_out_unit;
    double start_temp;
    char temp_start_unit;
    double output_temp;
    bool func_applied_successfully;

    func_applied_successfully = false;

    cout << "======================||Temperature Converter||======================" << endl;

    cout << "**Please input the unit of your starting temperature(K, C, F, or R)**" << endl;
    cin >> temp_start_unit;
    cout << "**************|Please input  your starting temperature|**************" << endl;
    cin >> start_temp;
    cout << "*Please input the unit your would like to convert to (K, C, F, or R)*" << endl;
    cin >> temp_out_unit;

    switch (temp_out_unit){
        case 'K':
        case 'k':
            if (temp_start_unit == 'R' || temp_start_unit == 'r'){
                output_temp = R2K(start_temp);
                func_applied_successfully = true;
            }
            else if (temp_start_unit == 'C' || temp_start_unit == 'c'){
                output_temp = C2K(start_temp);
                func_applied_successfully = true;
            }
            else if (temp_start_unit == 'F' || temp_start_unit == 'f'){
                output_temp = C2K(F2C(start_temp));
                func_applied_successfully = true;
            }
            else{
                cout << "HEY " << temp_start_unit << " IS NOT A STANDARD UNIT OF TEMPERATURE MEASUREMENT! I\'m leaving!"<< endl;
            }
            break;

        case 'C':
        case 'c':
            if (temp_start_unit == 'R' || temp_start_unit == 'r'){
                output_temp = K2C(R2K(start_temp));
                func_applied_successfully = true;
            }
            else if (temp_start_unit == 'K' || temp_start_unit == 'k'){
                output_temp = K2C(start_temp);
                func_applied_successfully = true;
            }
            else if (temp_start_unit == 'F' || temp_start_unit == 'f'){
                output_temp = F2C(start_temp);
                func_applied_successfully = true;
            }
            else{
                cout << "HEY " << temp_start_unit << " IS NOT A STANDARD UNIT OF TEMPERATURE MEASUREMENT! I\'m leaving!"<< endl;
            }
            break;

        case 'R':
        case 'r':
            if (temp_start_unit == 'K' || temp_start_unit == 'k'){
                output_temp = K2R(start_temp);
                func_applied_successfully = true;
            }
            else if (temp_start_unit == 'C' || temp_start_unit == 'c'){
                output_temp = K2R(C2K(start_temp));
                func_applied_successfully = true;
            }
            else if (temp_start_unit == 'F' || temp_start_unit == 'f'){
                output_temp = K2R(C2K(F2C(start_temp)));
                func_applied_successfully = true;
            }
            else{
                cout << "HEY " << temp_start_unit << " IS NOT A STANDARD UNIT OF TEMPERATURE MEASUREMENT! I\'m leaving!"<< endl;
            }
            break;

        case 'F':
        case 'f':
            if (temp_start_unit == 'R' || temp_start_unit == 'r'){
                output_temp = C2F(K2C(R2K(start_temp)));
                func_applied_successfully = true;
            }
            else if (temp_start_unit == 'C' || temp_start_unit == 'c'){
                output_temp = C2F(start_temp);
                func_applied_successfully = true;
            }
            else if (temp_start_unit == 'K' || temp_start_unit == 'k'){
                output_temp = C2F(K2C(start_temp));
                func_applied_successfully = true;
            }
            else{
                cout << "HEY " << temp_start_unit << " IS NOT A STANDARD UNIT OF TEMPERATURE MEASUREMENT! I\'m leaving!"<< endl;
            }
            break;
        default:
            cout << "HEY " << temp_out_unit << " IS NOT A STANDARD UNIT OF TEMPERATURE MEASUREMENT! I\'m leaving!"<< endl;
            break;

    }
    if (func_applied_successfully){
        cout << start_temp << " in " << (char)toupper(temp_start_unit) << " is " << output_temp << " in " << (char)toupper(temp_out_unit) << '.' << endl;
    }
    else{
        cout << "The requested conversion has failed because the converter left." << endl;
        cout << "Try providing proper temperature units next time." << endl;
    }
    cout << "=====================================================================" << endl;
    return 0;
}
