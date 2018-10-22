/* prog0404.c */

#include <stdio.h>

struct JINKOU {
    char ken[20];
    int num;
};

void quick_sort(struct JINKOU data[], int left, int right)
{
  int i,j,pivot;
  struct JINKOU tmp;

  if (left >= right){
    return;
  }
  i = left;
  j = right;

  pivot = data[(i+j)/2].num;

  while( 1 ){
    while(pivot < data[i].num){
      i++;
    }
    while(pivot > data[j].num){
      j--;
    }
    if (i >= j)
      break;
    tmp = data[i];
    data[i] = data[j];
    data[j] = tmp;
    i++;
    j--;
  }
  quick_sort(data,left,i-1);
  quick_sort(data,j+1,right);
}

void print_jinkou(struct JINKOU data[], int n)
{
    int i;
    for( i=0 ; i<n ; i++ ){
        printf("%d : %s : %d\n", i+1, data[i].ken, data[i].num);
    }
}

int main(void)
{
    struct JINKOU jinkou[47] = {
        {"北海道",5400},         {"青森県",1321},         {"岩手県",1284},
        {"宮城県",2328},         {"秋田県",1037},         {"山形県",1131},
        {"福島県",1935},         {"茨城県",2919},         {"栃木県",1980},
        {"群馬県",1976},         {"埼玉県",7239},         {"千葉県",6197},
        {"東京都",13390},        {"神奈川県",9096},     {"新潟県",2313},
        {"富山県",1070},         {"石川県",1156},         {"福井県",790},
        {"山梨県",841},            {"長野県",2109},         {"岐阜県",2041},
        {"静岡県",3705},         {"愛知県",7455},         {"三重県",1825},
        {"滋賀県",1416},         {"京都府",2610},         {"大阪府",8836},
        {"兵庫県",5541},         {"奈良県",1376},         {"和歌山県",971},
        {"鳥取県",574},            {"島根県",697},            {"岡山県",1924},
        {"広島県",2833},         {"山口県",1408},         {"徳島県",764},
        {"香川県",981},            {"愛媛県",1395},         {"高知県",738},
        {"福岡県",5091},         {"佐賀県",835},            {"長崎県",1386},
        {"熊本県",1794},         {"大分県",1171},         {"宮崎県",1114},
        {"鹿児島県",1668},     {"沖縄県",1421}
    };

    quick_sort( jinkou, 0, 46 );

    print_jinkou( jinkou, 47 );

    return 0;
}
