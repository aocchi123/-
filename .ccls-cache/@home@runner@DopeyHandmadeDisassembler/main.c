#include <stdio.h>
#define X -1
#define INF 99999
#define MAXNODE 9

struct MapType {
   int done;//1:すでに拠点になったことがある　0:ない 
   int dist;//暫定距離（0～INF)
   int memo;//来た場所をメモっておく(0-MAXNODE)
};

int showMap(struct MapType Map[]){
    for (int i=0; i<MAXNODE ; i++){
        printf("i=%d done=%d dist=%d memo=%d\n",i,
            Map[i].done, Map[i].dist, Map[i].memo);
    }
    return 0;
};

int main(void) {
    int ar[][MAXNODE] = {
        {X, 2, X, 1, X, X, X, X, X},//0
        {2, X, 2, X, 3, X, X, X, X},//1
        {X, 2, X, X, X, 2, X, X, X},//2
        {1, X, X, X, 1, X, 2, X, X},//3
        {X, 3, X, 1, X, 3, X, 3, X},//4
        {X, X, 2, X, 3, X, X, X, 1},//5
        {X, X, X, 2, X, X, X, 1, X},//6
        {X, X, X, X, 3, X, 1, X, 2},//7
        {X, X, X, X, X, 1, X, 2, X},//8
    };
    int base = 0;//最初の拠点は0
    int goal = 8;//ゴール
    struct MapType Map[MAXNODE] = {
        {1,   0, 0},//0 ノード0の初期状態
        {0, INF, 0},//1 
        {0, INF, 0},//2 
        {0, INF, 0},//3 
        {0, INF, 0},//4 
        {0, INF, 0},//5 
        {0, INF, 0},//6 
        {0, INF, 0},//7 
        {0, INF, 0},//8 
    } ;
    int loop_count = 0;//ループ回数
    int cost = 0;//スタートからのコスト
    int zantei = 0;//暫定ベスト距離
    while (1){
       printf("=============== loop count %d base=%d\n",loop_count,base) ;
       //直接つながっている道を見つける
            for (int i = 0; i<MAXNODE; i++){
                cost = ar[base][i];//2点間のコスト、距離
                if (cost > 0){
                   //暫定距離の計算と更新
                    zantei = Map[base].dist+cost ;
                    //比較　更新
                    if (zantei < Map[i].dist){
                        Map[i].dist = zantei;
                        Map[i].memo = base;
                    }
                }
            }
            showMap(Map);
        
       //拠点の決定
        //暫定距離の最小値を求める
        int mini = INF;
        int memo = 0;
        for (int i = 0; i < MAXNODE; i++){
            if (Map[i].done == 0){
            if (Map[i].dist < mini) {
                mini = Map[i].dist;
                memo = i;
            }   
            printf("i=%d mini = %d  memo = %d\n", i, mini, memo);
            }
        }
        base = memo;
        Map[base].done = 1;
        printf("next base=%d\n", base);
        showMap(Map);
        //終了条件
        if (base == goal){
            printf("goal!");
            break;
        }
        loop_count += 1;
        // //ダミー　
        // if (loop_count > 20)強制終了用　後で消す
        //     {break;}
    }
    return 0;
}