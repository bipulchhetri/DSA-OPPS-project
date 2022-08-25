#include<iostream>
#include<vector>
#include"datamodel.h"
using namespace std;
vector<Product>allProduct={
    Product(1,"Rice",40),
    Product(2,"oil",190),
    Product(3,"Dal",100),
    Product(4,"onion",40),
    Product(5,"Atta",40),
    Product(6,"salt",15),
    Product(7,"haldi",150),
    Product(8,"sugar",45),

};
Product * ChooseProduct()
{
    string ProductList;
    cout<<"Available Prodcut"<<endl;
    for(auto product:allProduct)
    {
        ProductList.append(product.getDisplayName());

    }
    cout<<ProductList<<endl;
    cout<<"-------------"<<endl;
    string choice;
    cin>>choice;
    for(int i=0;i<allProduct.size();i++)
    {
        if(allProduct[i].getShortName()==choice)
        {
            return &allProduct[i];
        }
    }
    cout<<"Product not found !"<<endl;
    return NULL;
}



bool checkout(Cart &cart)
{
    if(cart.isEmpty())
    {
        return false;
    }



    int total=cart.getTotal();
    cout<<"pay in cash";
   
    int paid;
    cin>>paid;



    if(paid>=total)
    {
        cout<<"change"<<paid-total<<endl;
        cout<<"Thank you for shopping !";
        return true;
    }
else{
    cout<<"Not enough cash!";
    return false;
}
}
int main(){

	char action;
	Cart cart;

	while(true){
		cout<<"Select an action -  (a)dd item, (v)iew cart, (c)heckout" <<endl;
		cin>> action;

		if(action=='a'){
			//Todo: Add to Cart 
			// View All Products + Choose Product + Add to the Cart 
			Product * product =ChooseProduct ();
			if(product!=NULL){
				cout<<"Added to the Cart "<<product->getDisplayName() <<endl;
				cart.addProduct(*product);
			}

		}
		else if(action=='v'){
			// View the Cart
			cout<<"------------------" <<endl;
			cout << cart.viewCart();
			cout<<"------------------"<<endl;
		}
		else{
			// Checkout 
			cart.viewCart();
			if(checkout(cart)){
				break;
			}
		}
	}

	return 0;
}