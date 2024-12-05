#include<stdio.h>
#include<math.h>
int main(){
	int arr[100];
	int n,choice;
	do{
	printf("\n MENU \n");
	printf("1. Nhap so phan tu va gia tri cho mang.\n");
	printf("2. In ra cac phan tu trong mang.\n");
	printf("3. Dem so luong cac so nguyen to trong mang.\n");
	printf("4. Tim gia tri nho thu hai trong mang.\n");
	printf("5. Them mot phan tu ngau nhien vao mang.\n");
	printf("6. Xoa phan tu tai vi tri ban muon.\n");
	printf("7. Sap xep 1 mang theo thu tu giam dan.\n");
	printf("8. Tim kiem 1 phan tu trong mang.\n");
	printf("9. Xoa toan bo phan tu trung lam trong mang va in ra cac phan tu doc nhat.\n");
	printf("10. Dao nguoc cac phan tu trong mang.\n");
	printf("11. Thoat.\n");
	printf("Lua chon cua ban la: ");
	scanf("%d",&choice);
	switch (choice){
		case 1: {// Nhap so phan tu va gia tri cho mang.
		do{
			printf("Nhap vao so luong phan tu trong mang: ");
			scanf("%d",&n);
			for(int i=0;i<n;i++){
				printf("Nhap vao gia tri cho phan tu arr[%d]: ",i);
				scanf("%d",&arr[i]);
			}
		}while(n<0);
		break ;
		}
		case 2:{//In ra cac phan tu trong mang
			for(int i=0;i<n;i++){
				printf(" arr[%d]=%d, ",i,arr[i]);
			}
			break;
		}
		case 3:{//Dem so luong cac so nguyen to trong mang
			int count=0;
			for (int i = 0; i < n; i++) {
        		int numb = arr[i];
        		if (numb < 2) {
            	continue; 
        		}
        		int element = 1; 
        		for (int j = 2; j <= sqrt(numb); j++) {
            		if (numb%j==0){
                	element = 0;
                	break;
            		}
        		}
        		if(element){
            	count+=1;
        		}
    		}printf("So luong so nguyen to la: %d",count);
			break;
		}
		case 4 :{// tim so nho thu 2.
			int firstMin=arr[0];
			for(int i=0;i<n;i++){
				if(arr[i]<firstMin){
					firstMin=arr[i];
				}
			}
			int secondMin=arr[n-1];
			for(int i=0;i<n;i++){
				if(arr[i]>firstMin&&arr[i]<secondMin){
					secondMin=arr[i];
				}
			}
			printf("So nho thu 2 torng mang la: %d",secondMin);
			break;
		}
		case 5 :{//them 1 phan tu vao mang
			int pos, value;
			do{
				printf("Nhap vi tri  muon them: ");
				scanf("%d",&pos);
			} while(pos<0&&pos>n+1);
			printf("Nhap gia tri ma ban muon them: ");
			scanf("%d",&value);
			for(int i=n;i>=pos;i--){
				arr[i]=arr[i-1];
				} 
			arr[pos-1]=value;
			printf("Mang sau khi them la: ");
			for(int i=0;i<n+1;i++){
				printf("%d ",arr[i]);
				}
				++n;
			break;
		}
		case 6:{ //Xoa phan tu tai vi tri cu the
			int pos;
			do{
				printf("Nhap vao vi tri phan tu ban muon xoa: ");
				scanf("%d",&pos);
			} while (pos>=n&&pos<0);
			for(int i=pos-1;i<n;i++){
				arr[i]=arr[i+1];
				}
			printf("Mang sau khi xoa gia tri la: ");
			for(int i=0; i<n-1;i++){
				printf("%d ",arr[i]);
			}
			--n;
			break;
		}
		case 7:{ // sap xep mang theo thu tu giam dan.
			int key;
			for(int i=1;i<n;i++){
				key=arr[i];
				for(int j=i-1;j>=0&&arr[j]<key;j--){
					arr[j+1]=arr[j];
					arr[j]=key;
					}
				}
			printf("Mang da hoan doi la: ");
			for(int i=0;i<n;i++){
				printf("%d ",arr[i]);
			}
			break;
		}
		case 8: {// tim kiem 1 phan tu trong mang bang binary seach.
			break;
		}
		case 9: {//  Xoa toan bo phan tu trung lam trong mang va in ra cac phan tu doc nhat.
			break;
		}
		case 10:{// dao nguoc mang.
			int j=n-1;
			for(int i=0;i<n/2;i++){
				int temp=arr[i];
				arr[i]=arr[j];
				arr[j]=temp;
				--j;
			}
			printf("Mang sau khi da dao nguoc la: ");
			for(int i=0;i<n;i++){
				printf("arr[%d]=%d ",i,arr[i]);
			}
			break;
		}
		case 11:{// thoat chuong trinh
			printf("Thoat chuong trinh.");
			return 0;
		}
		default:{
			printf("Lua chon khong hop le vui long chon lai");
			break;
		}
	}
	} while(choice>0);
	return 0;
}
