#ifndef Sb_H
#define Sb_H
#include<bits/stdc++.h>
#include<string>
#include "I.h"
#include "R.h"
#include "S.h"
using namespace std;
string funn3S(string Mnemonics)
{
    if(Mnemonics=="beq")
    return "000";
    else if(Mnemonics=="bne")
    return "001";
    else if(Mnemonics=="bge")
    return "101";
    else //blt
    return "100";
}
string Sb(string s,int j,string Mnemonic)
{
    string rs1="";
    string rs2="";
    string imm="";
    string ans="";
    int flag=0;
    for(int i=j;i<s.size();i++)
    {
        if(s[i]=='x' && flag==0)
        {
            i++;
            while(s[i]!=',' && s[i]!=' ')
            {
                rs2=rs2+s[i];
                i++;
            }
                flag++;
        }
        else if(flag==1 && s[i]!=' ')
        {
            while(s[i]!='(')
            {
                imm=s[i]+imm;
                i++;
            }
            flag++;
        }
        else if(flag==2 && s[i]!=' ')
        {
            if(s[i]=='x')
            {
                i++;
                while(s[i]!=')' && s[i]!=' ')
                {
                    rs1=rs1+s[i];
                    i++;
                }
                break;
            }
        }
    }
    //Adding opcode
    ans=ans+"1100011";
    //Adding imm[4:1]|11
    int imm_num=stoi(imm);
    string imm_complete=dectobin(imm_num,12);
    string imm1=imm_complete.substr(0,5);//imm1=imm[4:1]|11
    ans=imm1+ans;
    //Adding func3
    string fun3=funn3S(Mnemonic);
    ans=fun3+ans;
    //Adding rs1
    int rs1_num=stoi(rs1);
    ans=dectobin(rs1_num,5)+ans;
    //Adding rs2
    int rs2_num=stoi(rs2);
    ans=dectobin(rs2_num,5)+ans;
    //Adding imm[11:5]
    string imm2=imm_complete.substr(5,7);
    ans=imm2+ans;
    //converting binary to hexa
    string hex=bintodec(ans);
    //returning in hexadecimal
    return hex;

}
#endif
