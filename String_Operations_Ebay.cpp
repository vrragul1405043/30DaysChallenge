void DELETE_OPERATION(string& s, stack<pair<string,string>>&undo_stack){
    int SIZE = s.size();
    if(SIZE == 0) return;
    pair<string,string>p;
    p.first = "DELETE";
    p.second = s[SIZE-1];
    undo_stack.push(p);
    s = s.substr(0,SIZE-1); 
}

void INSERT_OPERATION(string& s, string text, stack<pair<string,string>>&undo_stack){
    if(text.size()==0)return;
    pair<string,string>p;
    p.first = "INSERT";
    p.second = text;
    undo_stack.push(p);
    s = s + text;
}

void COPY_OPERATION(string& s, int idx, string& clipboard){
    if(idx>=s.size())return;
    clipboard = s.substr(idx,s.size());
}

void PASTE_OPERATION(string& s, string& clipboard, stack<pair<string,string>>&undo_stack){
    if(clipboard.size()==0)return;
    pair<string,string>p;
    p.first = "PASTE";
    p.second = clipboard;
    undo_stack.push(p);
    s = s + clipboard;
}

void UNDO_OPERATION(string& s, stack<pair<string,string>>&undo_stack){
    pair<string,string>p;
    p = undo_stack.top();
    undo_stack.pop();
    
    if(p.first == "INSERT" || p.first == "PASTE"){
        int diff = s.size() - p.second.size();
        s = s.substr(0,diff);
    }
    
    if(p.first == "DELETE"){
        s = s + p.second;
    }
    
}

string newTextEditor(vector<string> operations) {
    stack<pair<string,string>>undo_stack;
    string clipboard = "";
    string result = "";
    for(string operation : operations){
        if(operation == "DELETE"){
            DELETE_OPERATION(result,undo_stack);
        }
        
        else if(operation == "PASTE"){
            PASTE_OPERATION(result,clipboard,undo_stack);
        }
        
        else if (operation == "UNDO"){
            UNDO_OPERATION(result,undo_stack);
        }
        
        else{
            vector<string>words;
            string word = "";
            for(char c : operation){
                if(c == ' '){
                    words.push_back(word);
                    word = "";
                }
                else{
                    word+=c;
                }
            }
            if(word.size()>0)words.push_back(word);
            
            if(words[0] == "INSERT"){
                INSERT_OPERATION(result, words[1], undo_stack);
            }
            
            else if(words[0] == "COPY"){
                COPY_OPERATION(result, words[1][0]-'0' , clipboard);
            }
        }   
    }
    //result = (result.size()==0)?"Empty":result;
    return result;//(result.size()==0)?"Empty" : result;
}

    
    
}

