if(flag){
        for(int i=0;i<n;i++){
            if(ans[i] == post[i]) continue;
            else{
                cout<<"no\n";
                return;
            }
        }
    }else{
        cout<<"no\n";
        return;
    }