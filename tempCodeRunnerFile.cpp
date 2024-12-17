    void done()
    {
        std::cout << "anything else i can assist with? " << std::endl;
        std::cout << "1 for more, 2 for logout" << std::endl;
        std::cin >> selection;
        if (selection == 1)
        {
            accountAction();
        }   
        else if (selection == 2)
        {
            exit;
        }