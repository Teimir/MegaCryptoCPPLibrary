#pragma once
//@return int - error code @param boolean - silence(auto false)
int test(bool silent = false);

int init(int type, int key[]);

string Binary_encrypt(string s);
string Binary_decrypt(string s);


string Scyt_encrypt(string s);
string Scyt_decrypt(string s);

string Affine_encrypt(string s);

string Affine_decrypt(string s);

string Atbash_encrypt(string s);

string Atbash_decrypt(string s);

string Caesar_encrypt(string s, int offset, bool enc);

string Caesar_decrypt(string s, int offset, bool enc);

