//You can find the mex for any array using the following function
//k is the the number of times you want to find the mex of elements starting from the first element of a till k times.
??If you want to find the mex of the entire array k times, just multiply k by n while putting it in the function
vector <int> MEX(vector <int> &a, int k){
    int n=a.size();
    if(k>=n){
        int l=k/n;
        l=l%(n+1);
        k=k%n;
        int b=(n*(n+1))/2;
        for(i=0;i<n;i++){
            b-=a[i];
        }
        a.push_back(b);
        rotate(a.begin(), a.end()-l, a.end());
    }
    set <int> update;
    map <int, int> frequency;
    for(i=0;i<n;i++){
        frequency[a[i]]++;
    }
    for(i=0;i<=n+1;i++){
        update.insert(i);
        if(frequency[i]>0){
            update.erase(i);
        }
    }
    for(i=0;i<k;i++){
        frequency[a[i]]--;
        int sample=a[i];
        a[i]=*(update.begin());
        update.erase(update.begin());
        if(frequency[sample]==0){
            update.insert(sample);
        }
        frequency[a[i]]++;
    }
    return a;

}
