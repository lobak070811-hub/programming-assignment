void editProperty(){
	
    string searchID;

    cout << "\n=============================\n";
    cout << "        EDIT PROPERTY\n";
    cout << "=============================\n";

    cout << "Enter Property ID: ";
    cin >> searchID;

    ifstream file("Property.txt");//read file

    if (!file)
    {
        cout << "Cannot open Property.txt\n";
        return;
    }

    vector<Property> properties;//copy&save all information in vector

    string line;
    bool found = false;

    while (getline(file, line))//keep on read the file
    {
        stringstream ss(line);

        Property p;

        getline(ss, p.propertyID, ',');
        getline(ss, p.roomType, ',');
        getline(ss, p.propertyName, ',');
        getline(ss, p.location, ',');
		//different parameter
        string price;
        string area;
        string distance;

        getline(ss, price, ',');
        getline(ss, area, ',');
        getline(ss, distance, ',');
		//change parameter from string to double(stod = string to double)
        p.price = stod(price);
        p.area = stod(area);
        p.distance = stod(distance);

        getline(ss, p.publisherID, ',');
        getline(ss, p.publisherName, ',');
        getline(ss, p.publisherPhone, ',');
        getline(ss, p.publisherRole);

        if (p.propertyID == searchID && p.publisherID == publisherID)
        {
            found = true;

            cout << "\nProperty found!\n";

            cin.ignore();

            cout << "New Property Name : ";
            getline(cin, p.propertyName);

            cout << "New Location      : ";
            getline(cin, p.location);

            cout << "New Price (RM)    : ";
            cin >> p.price;

            cout << "New Area (sqft)   : ";
            cin >> p.area;

            cout << "New Distance (km): ";
            cin >> p.distance;

            // Keep publisher information unchanged
        }
        properties.push_back(p);//push back to vector
    }

    file.close();

    if (!found)
    {
        cout << "\nProperty not found.\n";
        return;
    }

    // Rewrite Property.txt(from vector back into .txt file)
    ofstream outFile("Property.txt");

    for (int i = 0; i < properties.size(); i++)
    {
        outFile << properties[i].propertyID << ","
                << properties[i].roomType << ","
                << properties[i].propertyName << ","
                << properties[i].location << ","
                << properties[i].price << ","
                << properties[i].area << ","
                << properties[i].distance << ","
                << properties[i].publisherID << ","
                << properties[i].publisherName << ","
                << properties[i].publisherPhone << ","
                << properties[i].publisherRole
                << endl;
    }

    outFile.close();

    cout << "\n=====================================\n";
    cout << "       PROPERTY UPDATE SUCCESSFULLY\n";
    cout << "=====================================\n";

    cout << "Property ID     : " << p.propertyID << endl;
    cout << "Room Type       : " << p.roomType << endl;
    cout << "Property Name   : " << p.propertyName << endl;
    cout << "Location        : " << p.location << endl;
    cout << "Price           : RM" << p.price << endl;
    cout << "Area            : " << p.area << " sqft" << endl;
    cout << "Distance        : " << p.distance << " km" << endl;
    cout << "Published By    : " << p.publisherName << endl;
    cout << "Role            : " << p.publisherRole << endl;
    cout << "Phone           : " << p.publisherPhone << endl;

    cout << "====================================\n";
}
