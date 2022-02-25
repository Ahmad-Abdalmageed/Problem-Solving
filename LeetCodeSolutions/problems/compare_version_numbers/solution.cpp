class Solution {
public:
int compareVersion(string version1, string version2)
{
    int v1 = 0, v2 = 0;
    int i = 0, j = 0;

    while(i < version1.size() || j < version2.size())
    {
        cout << i << j << endl;
        // Excluding any leading zeros
        while(i < version1.size() && version1[i] != '.')
        {
            cout << "V1 : " << version1[i] << endl;
            v1 = v1*10 + (version1[i] - '0');
            i++;
        }
        while(j < version2.size() && version2[j] != '.')
        {

            cout << "V2 : " << version2[j] << endl;

            v2 = v2*10 + (version2[j] - '0');
            j++;
        }

        // check both versions
        if(v1 < v2){
            return -1;
        } else if(v1 > v2){
            return 1;
        }

        // Reset revisions and increment counters 
        // after ther dot operator
        v1 = 0;
        v2 = 0;
        i++;
        j++;
    }
    return 0;
}


};