#include<iostream>
#include<fstream>
#include<vector>
#include<string>

class documentElement{
    public:
        virtual std::string render()=0;
};

class textElement:public documentElement{
        std::string text;
    public:
        textElement(std::string text):text(text){}
        std::string render() override {
            return text + "\n";
        }
};

class imageElement:public documentElement{
        std::string path;
    public:
        imageElement(std::string path):path(path){}
        std::string render() override {
            return "[image] " + path + "\n";
        }
};

class document{
        std::vector<documentElement*> documentElements;
    public:
        void addElement(documentElement* d){
            documentElements.push_back(d);
        }
        std::string render(){
            std::string result;
            for(documentElement *d:documentElements){
                result += d->render();
            }
            return result;
        }
};

class persistence{
    public:
        virtual void save(std::string data)=0;
};

class saveToFile:public persistence{
    public:
        void save(std::string data){
            std::ofstream file("document.txt");
            file << data;
            file.close();
        }
};

class saveToDB:public persistence{
    public:
        void save(std::string data){
            //save to db
        }
};

class documentEditor{
    private:
        document* doc;
        persistence* storage;
        std::string renderedDocument;
    public:
        documentEditor(document* doc,persistence* storage):doc(doc),storage(storage){}
        void addText(std::string text){
            doc->addElement(new textElement(text));
        }
        void addImage(std::string path){
            doc->addElement(new imageElement(path));
        }
        std::string render(){
            if(renderedDocument.empty())
                renderedDocument = doc->render();
            return renderedDocument;
        }
        void save(){
            storage->save(render());
        }
};

int main(){
    document* doc = new document();
    persistence* storage = new saveToFile();
    documentEditor doce(doc,storage);
    doce.addText("hello");
    doce.addImage("hello.jpg");
    std::cout<< doce.render();
    doce.save();

    return 0;
}