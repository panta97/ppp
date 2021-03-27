#include "../std_lib_facilities.h"
/*
Sentence:
    Noun Verb
    Article Noun Verb
    Sentence Conjunction Sentence
*/

void putback_string(string char_stream)
{
    for (int i = char_stream.size() - 1; i >= 0; i--)
        cin.putback(char_stream[i]);
}

bool is_article(string word)
{
    return (word == "the");
}

bool is_noun(string word)
{
    return (word == "birds" || word == "fish" || word == "c++");
}

bool is_verb(string word)
{
    return (word == "rules" || word == "fly" || word == "swim");
}

bool is_conjunction(string word)
{
    return (word == "and" || word == "or" || word == "but");
}

bool article()
{
    bool isOK = false;
    string next;
    cin >> next;
    while (true)
    {
        if (is_article(next))
        {
            isOK = true;
            cin >> next;
        }
        else
        {
            putback_string(next);
            return isOK;
        }
    }
}

bool noun()
{
    bool isOK = false;
    string next;
    cin >> next;
    while (true)
    {
        if (is_noun(next))
        {
            isOK = true;
            cin >> next;
        }
        else
        {
            putback_string(next);
            return isOK;
        }
    }
}

bool verb()
{
    bool isOK = false;
    string next;
    cin >> next;
    while (true)
    {
        if (is_verb(next))
        {
            isOK = true;
            cin >> next;
        }
        else
        {
            putback_string(next);
            return isOK;
        }
    }
}

bool conjunction()
{
    bool isOK = false;
    string next;
    cin >> next;
    while (true)
    {
        if (is_conjunction(next))
        {
            isOK = true;
            cin >> next;
        }
        else
        {
            putback_string(next);
            return isOK;
        }
    }
}

bool sentence()
{
    bool isOK = false;

    while (true)
    {
        if (noun() && verb())
        {
            isOK = true;
        }
        else if (article() && noun() && verb())
        {
            isOK = true;
        }
        else if (conjunction() && sentence())
        {
            isOK = true;
        }
        else
        {
            isOK = false;
        }

        string next;
        cin >> next;
        if (next == "." || !isOK)
        {
            while (next != ".")
                cin >> next; //clear buffer
            putback_string(next);
            return isOK;
        }
        putback_string(next);
    }
}

int main()
{
    try
    {
        bool isOK = false;
        cout << "Enter an english phrase:" << endl;
        while (cin)
        {
            string next;
            cin >> next;
            if (next == ".")
                cout << "The phrase " << (isOK ? "is OK" : "is not OK") << endl;
            else
            {
                putback_string(next);
                isOK = sentence();
            }
        }
    }
    catch (exception &e)
    {
        cerr << "error: " << e.what() << '\n';
        keep_window_open();
        return 1;
    }
    catch (...)
    {
        cerr << "oh ouh unknown exception" << '\n';
        keep_window_open();
        return 2;
    }
}
