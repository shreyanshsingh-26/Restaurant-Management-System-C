#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<conio.h>       //getch()

#define NUM_RESTAURANTS 16
#define MAX_ITEMS 120
#define GST 0.18f

typedef struct{
    char name[256];
    float price;
    int stock;

} MenuItem;

// ------- Customer Details -------- //
typedef struct {
    char username[200];
    char password[200];
    char name[200];
    char phone[30];
    char address[300];
} Customer;


//------------ restaurants -------------//

const char *restaurants [NUM_RESTAURANTS] = {
    "Burger King",
    "Mc Donald",
    "Domino's",
    "Pizza Hut",
    "Starbucks",
    "Punjabi Anghiti",
    "Chinese Wok",
    "Call Me Chow",
    "Olio's Italian House",
    "Biryani's Blues",
    "KFC SECTOR 62",
    "Roastry Coffe House",
    "Momo's Bar",
    "Dial A Cake",
    "The Hazzle Nut Factory",
    "Baskin Robbin's",
};

const char *menus[NUM_RESTAURANTS][60] = {

    //1. Burger King //
    {
        "COLD DRINK (500ML)|40",
        "CRISPY VEG|59",
        "VEG CRUNCHY TACO|90",
        "REGULAR FRIES|89",
        "CHOCOLATE MOUSSE CUP|119",
        "MEDIUM FRIES|119",
        "KOREAN SAUCE BURST BURGER|119",
        "WHOPPER VEG|129",
        "CLASSIC COLD COFFEE|139",
        "HOT CHOCOLATE|139",
        "MOLTEN CHEESE LAVA DELUX BURGER|159",
        "FLAME GRILL CHICKEN BURGER|159",
        "BK FUSION SHAKE|180",
        "PANEER ROYALE WRAP|189",
        "CHICKEN TANDOORI BURGER|229",
      NULL
    },

    // 2.Mc Donald //
    {
      "McALOO TIKKI BURGER DOUBLE PATTY|58",
      "CHOCOLATE MILK SHAKES|75",
      "VEG-SURPRISE BURGER|79",
      "FRESH BREW COFFEE W MILK|86",
      "McFLAVOUR FRIES (REG.)|114",
      "COLD COFFEE|122",
      "McFLAVOUR FRIES (MED.)|147",
      "CHICKEN McGRILL DOUBLE PATTY BURGER|168",
      "CRISPY VEGGIE BURGER|196",
      "EVM McALOO TIKKI BURGER|207",
      "EVM BUTTER PANEER GRILLED BURGER|265",
      "McCRISPY CHICKEN DOUBLE PATTY BURGER|332",
      "CRICKET WALI PARTY COMBO-VEG|429",
      "McVEGGIE/McCHICKEN(ANY TWO)+1 MEDIUM FRIES +2 McPUFF|420",
      "LARGE EVM McSPICY CHICKEN DOUBLE PATTY BURGER|498",
      NULL
    },

    // 3. DOMINOS //
    {
      "COLD DRINK(500ML)|40",
      "CHEESE STUFFED GARLIC BREAD|117",
      "MARGHERITA PIZZA|119",
      "CHOCO LAVA CAKE|139",
      "MAKHANI PEPPORONI GARLIC BREAD|159",
      "PANEER CAPSICUM|109",
      "VEG LOADED|189",
      "PEPPER BARBECUE CHICKEN PIZZA|259",
      "PEPPY PANEER PIZZA|279",
      "ACCHARI DO PYAZA PIZZA|299",
      "MEXICAN GREEN WAVE PIZZA|349",
      "TANDOORI CHICKEN BURST PIZZA|349",
      "PEPPORINI PIZZA|349",
      "KOREAN CHICKEN SAUCE FLAVOURED|389",
      "SPECIAL PARTY FOR TWO|849",
      NULL
    },

    // 4. PIZZA HUT //
    {
      "PEPSI 475ML|57",
      "CHOCO VOLCANO|99",
      "LOADED BREAD STIX|99",
      "CLASSIC ONION CAPSICUM|109",
      "SPRINKLED FRIES-NEW|109",
      "CHEESE GARLIC BREAD|159",
      "MARGHERITA|169",
      "CHILLI PANEER SIZZLE|189",
      "SPICY RED SCHEZWAN PASTA + 2 PC PLAIN GARLIC BREAD|239",
      "VEGGIE FEAST|259",
      "TANDOORI PANEER|319",
      "COUNTRY FEAST|319",
      "VEGGIE SUPREME|379",
      "CHICKEN PAPPERANI|379",
      "CHICKEN TIKKA ULTIMATE CHEESE PIZZA|454",
      NULL
    },

    // 5. STARBUCKS //
    {
      "MANGO DRAGONFRUIT REFRESHER|125",
      "MASALA POTATO PUFF|180",
      "JAVA CHIP FRAPPUCCINO|190",
      "CAPPUCCINO|215",
      "MARGHARITA FLATBREAD|215",
      "LATTE|220",
      "FILTER COFFEE|220",
      "SIGNATURE HOT CHOCOLATE|230",
      "GREEN TEA LATTE|280",
      "CHOCOLATE CHIP COOKIE|290",
      "ALMOND BUTTERSCOTCH COOKIE|290",
      "ICED SIGNATURE CHOCOLATE|295",
      "HAZELNUT CAFFE LATTE|305",
      "WHITE CHOCOLATE MOCHA|310",
      "TOFU SPINACH CROISSANT|345",
      NULL
    },

    // 6. PUNJABI ANGHITI //
    {
      "WATER BOTTLE|20",
      "TANDOORI ROTI (2)|30",
      "TANDOORI NAAN (2 PLAIN)|35",
      "TANDOORI NAAN (2 BUTTER)|45",
      "SALAD|75",
      "JEERA RICE(400g)|115",
      "VEG PULAO(400g)|135",
      "DAL TADKA|215",
      "MASALA CHAAP GRAVY|225",
      "DAL MAKHANI|235",
      "KADHAI PANEER|255",
      "PANEER LABABDAR|255",
      "TANDORI MASALA SOYA CHAAP|265",
      "2 ALOO PARATHA WITH RAITAA|285",
      "MALAI KOFTA|295",
      NULL
    },

    // 7. CHINESE WOK //
    {
      "VEG FRIED RICE(500g)|169",
      "VEG CLASSIC MOMO (8 PIECE)|169",
      "HONEY CHILLI POTATO (500g)|169",
      "VEG HAKKA NOODLES(500g)|179",
      "PANEER CHILLI DRY(500g)|185",
      "MANCHURIAN DRY (500g)|185",
      "EGG HAKKA NOODLES(500g)|189",
      "VEG CHILLI GARLIC NOODLES(500g)|199",
      "CHICKEN CLASSIC MOMO (8 PIECE)|199",
      "CHICKEN FRIED RICE(500g)|205",
      "PANEER 65 (500g)|235",
      "CHICKEN 65 (500g)|255",
      "PEPPER PANEER CLASSIC BOWL (500g)|265",
      "KUNG PAO CHICKEN BOWL (500g)|295",
      "PANEER POT RICE (500g)|345",
      NULL
    },

    // 8. CALL ME CHOW //
    {
      "CLASSIC FRIED RICE|129",
      "VEG CHILLI GARLIC NOODLES|139",
      "STREET STYLE CHOWMEIN|139",
      "CHICKEN HAKKA NOODLES|149",
      "EGG FRIED RICE|149",
      "VEG MANCHURIAN DRY|149",
      "CHICKEN CHILLI GARLIC NOODLES|179",
      "CHILLI PANEER|179",
      "CHICKEN CHILLI GARLIC FRIED RICE|179",
      "KOREAN FRIED POTATO|198",
      "PANEER VEG MOMOS-STEAMED|199",
      "HONGS PAD THAI NOODLE VEG|218",
      "SCHEZWAN PANEER|229",
      "CLASSIC HAKKA NOODLES|239",
      "PANEER MOMO GREEN THAI+SPRITE|269",
      NULL
    },

    // 9. OLIO'S ITALIAN HOUSE //
    {
      "CLASSIC BREAD STIX|120",
      "CHEESY BREAD STIX|145",
      "CHOCOLATE BROWNIE|160",
      "CHICKEN PERI PERI FRIES|180",
      "VEG CHEESE GRILLED SANDWICH|210",
      "CHICKEN DELIGHT GRILLED SANDWICH|235",
      "PESTO VEGGIE GRILLED SANDWICH|245",
      "PESTO GARLIC BREAD|249",
      "SIGNATURE GARLIC KNOT WITH CHEESY DIP (10 PIECE)|250",
      "SIGNATURE CHICKEN TIKKA KNOT WITH CHEESY DIP (10 PIECE)|295",
      "BAKED MAC & CHEESE|315",
      "SPAGHETTI RED SAUCE|329",
      "SPAGHETTI WITH 3 CHEESE|379",
      "BAKED MUSHROOM PASTA|395",
      "MARGRITA WOOD FIRE PIZZA|459",
      NULL
    },

    // 10. BIRYANI'S BLUE //
    {
      "FIERY POTATO 65|159",
      "FIERY PANEER 65|169",
      "CHICKEN SHAMMI KEBAB (8 PCS)|229",
      "GALOUTI KEBAB (8 PCS)|229",
      "EGG BIRYANI (SERVES 2)|349",
      "PEPPER CHICKEN BIRYANI (SERVES 2)|349",
      "SOYA CHAAP BIRYANI (SERVES 2)|379",
      "PANEER TIKKA BIRYANI (SERVES 2)|379",
      "LUCKNOW CHICKEN BONELESS BIRYANI (SERVES 2)|379",
      "HYDERABADI PANEER BIRYANI + RAITA (SERVES 2)|399",
      "CHICKEN DUM BIRYANI (BONELESS)|399",
      "VEG KEBAB PLATTER|425",
      "CHICKEN MALAI TIKKA (8 PCS)|459",
      "MUTTON SEEKH KEBAB (6 PCS)|499",
      "SIGNATURE CHICKEN PLATTER|549",
      NULL
    },

    // 11. KFC //
    {
      "CLASSIC FRIES|99",
      "SPICY CHICKEN BURGER|149",
      "CHEESY REGULAR FRIES|155",
      "GRILLED CHICKEN WRAP|189",
      "CRUNCHY CHICKEN STRIPS (4 PIECE)|199",
      "VEG RICE BOWL|219",
      "CHICKEN NUGGETS (8 PIECE)|229",
      "CHICKEN POPCORN MEDIUM|250",
      "CHICKEN POPCORN BIRYANI|250",
      "CLASSIC CHICKEN RICE BOWL|250",
      "GOLDEN CHICKEN ZINGER|250",
      "HOT CHICKEN WINGS (8 PIECES)|350",
      "CHICKEN & FRENCH FRIES BUCKET|350",
      "GRILLED SMOKY RED CHICKEN (6 PIECE)|459",
      "BIG 12 CHICKEN BUCKET|750",
      NULL
    },

    // 12. ROASTRY COFFEE HOUSE //
    {
      "GARLIC BREAD|160",
      "HOT CHOCOLATE|180",
      "CAPPUCCINO|195",
      "MOCHA|195",
      "BROWNIE|200",
      "ICED AMERICANO|215",
      "COLD BREW|225",
      "VANILLA SHAKE|229",
      "FLAT WHITE|235",
      "CAFFE LATTE|240",
      "CHOCOLATE SHAKE|249",
      "VEG CLUB SANDWICH|255",
      "SPINACH & CORN SANDWICH|290",
      "OREO BLEND COFFEE|325",
      "CHOCOLATE BLEND COFFEE|355",
      NULL
    },
    // 13. MOMO'S BAR //
    {
      "KESAR GULAB JAMUN (2PC)|69",
      "CHOCOLATE MOMO (1PC)|75",
      "COCA-COLA ZERO SUGAR 330 ML CAN|75",
      "THUMS UP 330 ML|75",
      "VEG HIMALAYAN FRIED PERI PERI MOMO|99",
      "VEG DARJEELING STEAM MOMO|109",
      "VEG HOT GARLIC STEAM MOMO|109",
      "VEG PAHARI FRESH FRIED MOMO|109",
      "VEG HOT GARLIC FRIED MOMO|109",
      "CHEESE VEGGIE MOBURG|129",
      "CHICKEN HIMALAYAN CHILLI MOMO|129",
      "CHATPATA PANEER STEAM MOMO|149",
      "VEG THUPKA SOUP|149",
      "CORN CHEESE KOREAN SPICY MOMO – NEW|169",
      "CORN CHEESE CHILLI MOMO|169",
      NULL
    },

    // 14. DIAL A CAKE //
    {
        "CHOCO CHIP BROWNIE|59",
        "MINI CHOCO LAVA CUP|99",
        "C|109",
        "CHOCOLATE TRUFFLE PASTRY|119",
        "VANILLA CUPCAKE|129",
        "RED VELVET DESERT JAR|149",
        "PINEAPPLE JAR CAKE|149",
        "BLACK FOREST PASTRY|149",
        "STRAWBERRY MOUSSE JAR|179",
        "CHOCOLATE MUD JAR|169",
        "BLUEBERRY CHEESECAKE JAR|189",
        "DEATH BY CHOCOLATE JAR|189",
        "CHOCOLATE JAR FUDGE|199",
        "BISCOFF CHEESECAKE JAR|219",
        "DUTCH CHOCOLATE TRUFFLE CAKE (500GM)|519",

      NULL
    },

    // 15. HAZLE NUT FACTORY //
    {
      "HERB GARLIC POTATO WEDGES|159",
      "CLASSIC TOMATO SOUP|179",
      "GREEK YOGURT GRANOLA BOWL|199",
      "VEGGIE LETTUCE WRAP|229",
      "SPINACH COTTAGE CHEESE WRAP|249",
      "MAC & CHEESE BURGER|275",
      "VEG POWER SMOOTHIE BOWL|299",
      "PEANUT BUTTER OATMEAL BOWL|325",
      "AVOCADO SALAD|355",
      "CHICKPEA & AVOCADO BOWL|355",
      "CAESAR SALAD|375",
      "RAGI & CORN NACHOS|475",
      "BURRITO BOWL|525",
      "TERIYAKI SAUCE WITH BROCCOLI RICE BOWL|525",
      "PENNE PINK SAUCE PASTA|525",
      NULL
    },

    // 16. BASKIN ROBBINS //
    {
      "BANANA 'N STRAWBERRRY ICE CREAM|95",
      "MISSISSIPPI MUD ICE CREAM|115",
      "MINT MILK COFFEE CHIPS ICE CREAM|115",
      "HOP SCOTCH BUTTERSCOTCH ICE CREAM|115",
      "CHOCOLATE & ROASTED HAZELNUT GELATO|125",
      "RED VELVET ICE CREAM|150",
      "VERY BERRY STRAWBERRY ICE CREAM|180",
      "BLUE BERRY ICE CREAM|200",
      "CHOCO LAVA CAKE SUNDAE (VANILLA)|215",
      "DUTCH CHOCOLATE MILKSHAKE|220",
      "ALPHONSO MANGO FRUIT CREAM SUNDAE|225",
      "BELGIAN BLISS ICE CREAM (TUB)|415",
      "TENDER COCONUT TUB|550",
      "CHOCOLATE LOVER'S SIGNATURE WAFFLE|335",
      "CHOCOLATE TRUFFLE ICE CREAM CAKE|643",
      NULL
    }
}; //end menu[][] //

//helpers//
void make_username(const char *in, char *out) {
    int j = 0;
    for (int i=0; in[i] && j<199; ++i){
        char c = in[i];
        if (c== ' ' || c== '\'' || c== '"' || c== '-' || c=='.')
        {
            c= '_';
        }
        if (c>= 'A' && c<= 'Z')
        {
            c = c - 'A' + 'a';
        }

        out [j++]= c;
        }
        out [j] = 0;
}

void clear_buffer() {
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF);
}

// Password masking using getch()//
void getPassword(char *pass, int maxLen)
{
    int i = 0;
    char ch;
    while (1)
    {
        ch = getch(); //read key, not echoed
        if (ch==13){   // ch==13 for enter
            pass[i] = '\0';
            printf("\n");
            break;
        } else if (ch==8) { //ch==8 for backspace
            if (i>0){
                i--;
                printf("\b \b");
            }
        } else if (i<maxLen - 1){
            pass[i++] = ch;
            printf("*");
            }
    }
}

// init files //
void init_files ()
{
    srand ((unsigned)time(NULL));
    FILE *f;

    // owners.txt: username password index file
    f=fopen("owners.txt","w");
    if (f){
        for (int i=0;i<NUM_RESTAURANTS;i++)
            {
                char uname[200];
                make_username(restaurants[i],uname);
                fprintf(f,"%s rest%d@123 %d\n",uname, i+1,i);
            }
            fclose(f);
     }

     //ensure customer file exists
     f=fopen("customers.txt","a");
     if (f){
        fclose(f);
        }

     // delivery ranges
    f=fopen("delivery.txt","w");
    if (f){
        for (int i=0;i<NUM_RESTAURANTS;i++){
            int mn=20+rand()%21;
            int mx=mn+10+rand()%11;
            fprintf(f,"%d %d\n",mn, mx);

        }
        fclose(f);
    }

    //create menuN.txt files
    for (int r=0;r<NUM_RESTAURANTS;r++){
        char fn[64];
        sprintf(fn,"menu%d.txt", r+1);
        f=fopen(fn,"w");
        if (!f) continue;
        for (int k=0; menus[r][k];k++){
            char buf[512];
            strncpy(buf, menus[r][k], sizeof(buf)-1);
            buf[sizeof(buf)-1]=0;
            char *sep=strchr(buf,'|');
            if (!sep) continue;
            *sep=0;
            float price=atof(sep+1);
            int stock=5+rand()%26;
            fprintf(f,"\"%s\" %.2f %d\n", buf, price, stock);
        }
        fclose(f);
    }

}

//load menu//
int load_menu(int r,MenuItem arr[])
{
    char fn[64];
    sprintf(fn,"menu%d.txt", r+1);
    FILE *f=fopen(fn,"r");
    if(!f) return 0;
    int c=0;
    char line[512];
    while (fgets(line,sizeof(line),f) && c<MAX_ITEMS){
        char nm[256];
        float pr;
        int st;
        if (sscanf(line, " \"%[^\"]\" %f %d",nm,&pr, &st)==3){
            strncpy(arr[c].name, nm , sizeof(arr[c].name)-1);
            arr[c].name[sizeof(arr[c].name)-1]=0;
            arr[c].price=pr;
            arr[c].stock=st;
            c++;
        }
    }
    fclose(f);
    return c;
}

//save menu//
void save_menu(int r, MenuItem arr[], int cnt)
{
    char fn[64];
    sprintf(fn,"menu%d.txt", r+1);
    FILE *f=fopen(fn,"w");
    if (!f)
        return;
    for(int i=0;i<cnt;i++){
        fprintf(f,"\"%s\" %.2f %d\n", arr[i].name, arr[i].price, arr[i].stock);
    }
    fclose(f);
}

//owner login (auto-detect the specific restaurant)
int owner_login()
{
    char user[200], pass[200], fu[200], fp[200];
    int idx;
    printf("Owner username: ");
    scanf("%199s", user);
    clear_buffer();
    printf("Password: ");
    getPassword(pass,200);

    FILE *f = fopen("owners.txt","r");
    if (!f) return -1;
    int found = -1;
    while (fscanf(f, "%199s %199s %d", fu, fp, &idx) == 3) {
        if (strcmp(user, fu) == 0 && strcmp(pass, fp) == 0) { found = idx; break; }
    }
    fclose(f);
    return found;
}

//customer login check//
int customer_login_check()
{
    char user[200], pass[200], fu[200], fp[200];

    printf("Username: ");
    scanf("%199s", user);
    clear_buffer();

    printf("Password: ");
    getPassword(pass, 200);

    FILE *f = fopen("customers.txt", "r");
    if (!f)
        return 0;

    int ok = 0;


    while (fscanf(f, "%199s %199s", fu, fp) == 2)
    {
        if (strcmp(user, fu) == 0 && strcmp(pass, fp) == 0)
        {
            ok = 1;
            break;
        }
    }

    fclose(f);
    return ok;
}


//Login File//
int login_file(const char *file)
{
    char u[200], p[200], fu[200], fp[200];

    printf("Username: ");
    scanf("%199s", u);

    printf("Password: ");
    getPassword(p, 200);

    FILE *f= fopen(file, "r");
    if (!f)
        return 0;
    int ok = 0;

    while (fscanf(f, "%199s %199s", fu, fp)==2 )
    {
        if (strcmp(fu, u)==0 && strcmp(fp, p)==0)
        {
            ok =1;
            break;
        }
    }
    fclose(f);
    return ok; //FOUND=1, NOT FOUND=0//
}

//Show Cart and return subtotal//
float show_car(MenuItem arr[], int idx[], int qty[], int n)
{
    float subtotal=0;

    printf("\n Items in Cart: \n");
    printf("-----------------------------------------------\n");

    for(int i=0; i<n; i++)
    {
        float price=arr[idx[i]].price;
        float total=price*qty[i];
        subtotal += total;

        char name[200];
        strcpy(name, arr[idx[i]].name);

        char line1[200], line2[200];

        //Wrap Long Names//
        if (strlen(name)<=45){
            printf("%2d ) %-45s  x%-3d  Rs%.2f\n",
                   i+1, line1, qty[i], total);
            printf("        %-45s\n", line2);
        }
    }

    printf("-----------------------------------------------\n");
    printf ("Subtotal: Rs%.2f\n", subtotal);

    return subtotal;
}

//show menu//
void show_menu(MenuItem arr[], int c, int r)
{
    system("cls"); //used to clear the console screen in the windows i.e. clear screen//

    //display title at the centre position//
    char title[200];
    sprintf(title, "--- %s --- ", restaurants[r]);

    int width = 80;
    int pad = (width - strlen(title))/2;
    for (int i=0; i<pad;i++)
        printf(" ");
    printf("%s\n\n", title);

    //table header//
    printf("%-4s %-45s %-12s %-6s\n",
           "No", "Item Name", "Price", "Stock");

    printf("-------------------------------------------\n");

    //Table rows with wrapping//
    for (int i=0; i<c;i++)
    {
        char line1[46], line2[46];
        int len=strlen(arr[i].name);

        //if the name fits in one line
        if (len<=45)
        {
            printf("%-4d %-45s Rs%-10.2f [%d]\n",
                   i+1, arr[i].name, arr[i].price, arr[i].stock);
        }
        else
        {
            //copy first 45 chars to line1//
            strncpy(line1, arr[i].name, 45);
            line1[45]= '\0';

            //remaining chars to line2 (upto 45 again)//
             strncpy(line2, arr[i].name+45, 45);
            line2[45]= '\0';

            //print line1 with number, price  and stock//
            printf("%-4d %-45s Rs%-10.2f [%d]\n",
                   i+1, line1, arr[i].price, arr[i].stock);

            //printf line 2 (NO NUMBER, NO PRICE)
            printf("        %-45s\n", line2);
        }
    }

    printf("\n");
}


//show bill//
float show_cart_bill(MenuItem arr[], int idx[], int qty[], int n)
{
    float sub=0;
    for (int i=0; i<n; i++)
    {
        float line = arr[idx[i]].price * qty[i];
        printf("%d) %s x%d = Rs&.2f\n", i+1, arr[idx[i]].name, qty[i], line);
        sub +=line;
    }
    float gst=sub*GST;
    float total=sub+gst;
    printf("Subtotal: Rs%.2f\nGST (18%%): Rs%.2f\nTOTAL: RS%.2f\n", sub, gst, total);
    return total;
}

//print bill//
void print_bill(MenuItem arr[], int idx[], int qty[], int n, float sub, float gst, float tot, char *pay)
{
    printf("\n Items Ordered: \n");
    printf("--------------------------------------------\n");

    for (int i=0; i<n;i++)
    {
        int m= idx[i];
        float line_total=arr[m].price * qty[i];

        printf("%2d) %-36s  x%-3d  Rs%8.2f\n",
               i+1, arr[m].name, qty[i], line_total);
    }

    printf("---------------------------------------------\n");

    printf("%40s Rs%8.2f\n", "Subtotal: ", sub);
    printf("%40s Rs%8.2f\n", "GST(18%): ", gst);
    printf("---------------------------------------------\n");
    printf("%40s Rs%8.2f\n", "TOTAL: ", tot);

    printf("\n Payment Method: %s\n", pay);
    printf("Transaction: SUCCESS \n");

    printf("**********************************************\n");
    printf("           Thank you for ordering with us!\n");
    printf("**********************************************\n");
}
int customer_login(Customer *cust) {
    char un[200], pw[200];

    printf("Username: ");
    scanf("%199s", un);
    clear_buffer();

    printf("Password: ");
    getPassword(pw, 200);

    FILE *f = fopen("customers.txt", "r");
    if (!f) {
        printf("Error opening customers.txt\n");
        return 0;
    }

    Customer temp;

    while (fscanf(f,
        "%199[^|]|%199[^|]|%199[^|]|%29[^|]|%299[^\n]\n",
        temp.username, temp.password, temp.name,
        temp.phone, temp.address) == 5)
    {
        if (strcmp(un, temp.username) == 0 &&
            strcmp(pw, temp.password) == 0)
        {
            *cust = temp;
            fclose(f);
            return 1;   // login success
        }
    }

    fclose(f);
    return 0;
}

//Customer Flow//
void customer_flow(int minD[], int maxD[])
{
    while (1)
    {
        printf("\n 1. Login");
        printf("\n 2. Signup ");
        printf("\n 3. Back");
        printf("\n Enter your choice: ");

        int c;
        scanf("%d", &c);

        //---Login---//
        if (c == 1)
            {
                Customer logged;   //

                // Login
                if (!customer_login(&logged)) {
                    printf("Login Failed.\n");
                    continue;
                }

                printf("\nWelcome %s!\n", logged.name);
                printf("Phone: %s\n", logged.phone);
                printf("Address: %s\n\n", logged.address);

                printf("\n Restaurants: \n");
                for (int i=0; i<NUM_RESTAURANTS;i++){
                    printf("%d) %s\n", i+1, restaurants[i]);
                }

                int r;
                printf("\n Enter your choice: ");
                scanf("%d", &r);

                if (r<1 || r>NUM_RESTAURANTS)
                    continue;

                r--; // index adjustment


            MenuItem arr[MAX_ITEMS];
            int  cnt=load_menu(r, arr);
            if (cnt==0)
            {
                printf("No Items Found.\n");
                continue;
            }

            int idx[100], qty[100], n=0;

            //  Add Items//
            while(1)
            {
                show_menu(arr, cnt, r);

                printf("Add item( Press 0 if u want to go back): ");
                int it;
                scanf("%d", &it);

                if (it==0)
                    break;

                if (it<1||it>cnt)
                    continue;

                printf("Qty: ");
                int q;
                scanf("%d", &q);

                if (q<=0|| q>arr[it - 1].stock)
                {
                    printf("Not Enough Stock. \n");
                    continue;
                }

                idx[n]= it-1;
                qty[n]=q;
                n++;

                char more;
                printf("Add More Items? (Y/N): ");
                scanf(" %c", &more);

                if (more!= 'Y' && more!= 'y')
                    break;
            }
            if (n==0)
                continue;

            //---Review Loop---//
            while (1)
            {
                float subtotal=0;
                for (int i=0; i<n;i++)
                    subtotal += arr[idx[i]].price * qty[i];

                float gst = subtotal*GST;
                float total = subtotal + gst;

              printf("\n************************************************************************\n");
                printf("*                           DINE-IN DELIGHT                            *\n");
                printf("*                        Official Order Invoice                        *\n");
                printf("************************************************************************\n");

                printf("\n Items Ordered: \n");
                printf("------------------------------------------------------------------------\n");

                for (int i=0; i<n; i++)
                    printf("%2d) %-35s x%-3d Rs%.2f\n",
                           i+1 ,arr[idx[i]].name, qty[i],
                           arr[idx[i]].price * qty[i]);

                printf("------------------------------------------------------------------------\n");
                printf("Subtotal: %42sRs%.2f\n", "", subtotal);
                printf("GST (18%%): %41sRs%.2f\n", "", gst);
                printf("------------------------------------------------------------------------\n");
                printf("Total: %45sRs%.2f\n", "", total);
                printf("------------------------------------------------------------------------\n");

                printf("F - Finalize\n M - Modify\n C - Cancel\n Enter Choice: ");
                char x;
                scanf(" %c", &x);

                //Cancel Order//
                if (x=='C' || x=='c')
                {
                    printf("Order Cancelled.\n");
                    break;
                }

                //Modify Cart//
                if (x=='M' || x=='m')
                {
                    printf("\n1) Remove Item \n2) Change Quantity \n Choose: ");
                    int op;
                    scanf("%d", &op);

                    if (op==1){
                        printf("Enter item number to remove: ");
                        int rm;
                        scanf("%d", &rm);

                        if (rm>=1 && rm<=n){
                            for(int i=rm-1;i<n-1;i++){
                                idx[i]=idx[i+1];
                                qty[i]=qty[i+1];
                            }
                            n--;
                        }
                    }
                    else if (op==2){
                        printf("Enter item number: ");
                        int no;
                        scanf("%d", &no);

                        if (no>=1 && no<=n){
                            printf("New qty: ");
                            int nq;
                            scanf("%d", &nq);

                            int mi=idx[no-1];

                            if (nq>0 && nq<=arr[mi].stock)
                                qty[no-1]=nq;
                        }
                    }
                    continue;
                }

                //finalize order//
                // -------- FINALIZE ORDER --------- //
                    if (x == 'F' || x == 'f')
                    {
                        // ------- PAYMENT METHOD ------- //
                        printf("\n Select Payment Method:\n");
                        printf("1) UPI\n");
                        printf("2) Credit/Debit Card\n");
                        printf("3) Net Banking\n");
                        printf("4) Cash on Delivery\n");

                        int pay;
                        printf("Enter Choice: ");
                        scanf("%d", &pay);

                        char method[40], status[20];
                        switch (pay)
                        {
                            case 1:
                                strcpy(method, "UPI");
                                strcpy(status, "SUCCESS");
                                break;
                            case 2:
                                strcpy(method, "Credit/Debit Card");
                                strcpy(status, "SUCCESS");
                                break;
                            case 3:
                                strcpy(method, "Net Banking");
                                strcpy(status, "SUCCESS");
                                break;
                            case 4:
                                 strcpy(method, "Cash on Delivery");
                                 strcpy(status, "PENDING");
                                 break;
                            default:
                                strcpy(method, "Unknown");
                                strcpy(status, "FAILED");
                                 break;
                        }

                        // -------- PRINT FULL BILL -------- //
                        system("cls");

                        printf("************************************************************************\n");
                        printf("*                           DINE-IN DELIGHT                            *\n");
                        printf("*                        Official Order Invoice                        *\n");
                        printf("************************************************************************\n\n");

                        printf(" Items Ordered:\n");
                        printf("------------------------------------------------------------------------\n");

                        float subtotal = 0;
                        for (int i = 0; i < n; i++)
                        {
                            float line = arr[idx[i]].price * qty[i];
                            subtotal += line;

                            printf("%2d) %-35s x%-3d Rs%.2f\n",
                                   i + 1,
                                   arr[idx[i]].name,
                                   qty[i],
                                   line);
                        }

                        float gst = subtotal * GST;
                        float total = subtotal + gst;

                        printf("------------------------------------------------------------------------\n");
                        printf("Subtotal:%45sRs%.2f\n", "", subtotal);
                        printf("GST (18%%):%44sRs%.2f\n", "", gst);
                        printf("------------------------------------------------------------------------\n");
                        printf("Total:%48sRs%.2f\n", "", total);
                        printf("------------------------------------------------------------------------\n\n");


                        // ------ CUSTOMER DETAILS ------ //
                        printf("-------------------- CUSTOMER DETAILS ----------------------------------\n");
                        printf("Name    : %s\n", logged.name);
                        printf("Phone   : %s\n", logged.phone);
                        printf("Address : %s\n", logged.address);
                        printf("------------------------------------------------------------------------\n\n");


                        // ------- PAYMENT DETAILS ------ //
                        printf("--------------------- PAYMENT DETAILS ----------------------------------\n");
                        printf("Payment Method: %s\n", method);
                        printf("Transaction   : %s\n", status);
                        printf("------------------------------------------------------------------------\n\n");


                        // ------- DELIVERY TIME ------ //
                        printf("Estimated Delivery: %d - %d minutes\n\n", minD[r], maxD[r]);

                        printf("---------------------- ORDER CONFIRMED ---------------------------------\n");
                        printf("Thank you for ordering with Dine-In Delight!\n");
                        printf("------------------------------------------------------------------------\n\n");


                        // ----- UPDATE STOCK ------ //
                        for (int i = 0; i < n; i++)
                            arr[idx[i]].stock -= qty[i];

                        save_menu(r, arr, cnt);

                        break;
                    }
                                    }
          }

               // --- Signup --- //
        if (c == 2) {
            Customer cust;
            char conf[200];

            printf("Choose Username: ");
            scanf("%199s", cust.username);
            clear_buffer();

            printf("Enter Password: ");
            getPassword(cust.password, 200);

            printf("Confirm Password: ");
            getPassword(conf, 200);

            if (strcmp(cust.password, conf) != 0) {
                printf("Passwords do not match!\n");
                continue;
            }

            printf("Enter Full Name: ");
            scanf(" %[^\n]", cust.name);

            printf("Enter Phone Number: ");
            scanf(" %[^\n]", cust.phone);

            printf("Enter Address: ");
            scanf(" %[^\n]", cust.address);

            FILE *f = fopen("customers.txt", "a");
            if (!f) {
                printf("Error writing customers.txt\n");
                continue;
            }

            fprintf(f, "%s|%s|%s|%s|%s\n",
                    cust.username, cust.password,
                    cust.name, cust.phone, cust.address);

            fclose(f);
            printf("Signup Successful!\n");
            continue;
        }

        //back//
        if (c==3)
            break;
    }
}


        //owner panel//
void owner_panel(int owner_rid, int minD[], int maxD[])
{
    if (owner_rid < 0 || owner_rid >= NUM_RESTAURANTS)
    {
        printf("Invalid owner.\n");
        return;
    }

    printf("Owner logged in for: %s\n", restaurants[owner_rid]);

    while (1)
    {
        printf("\n Owner Menu\n");
        printf("1. View Menu\n");
        printf("2. Restock Menu \n");
        printf("3. Change Delivery Time \n");
        printf("4. Logout \n");
        printf("Enter your choice: ");

        int op;
        if (scanf("%d", &op) != 1)
        {
            clear_buffer();
            break;
        }

        MenuItem arr[MAX_ITEMS];
        int cnt = load_menu(owner_rid, arr);

        if (op == 1)
        {
            show_menu(arr, cnt, owner_rid);
        }
        else if (op == 2)
        {
            show_menu(arr, cnt, owner_rid);

            printf("Item no.: ");
            int it;
            scanf("%d", &it);

            if (it < 1 || it > cnt)
            {
                printf("Invalid.\n");
                continue;
            }

            printf("Add qty: ");
            int q;
            scanf("%d", &q);

            if (q > 0)
            {
                arr[it - 1].stock += q;
                save_menu(owner_rid, arr, cnt);
                printf("Item Restocked.\n");
            }
        }
        else if (op == 3)
        {
            printf("Current delivery time: %d - %d\n", minD[owner_rid], maxD[owner_rid]);
            printf("New Minimum Time: ");
            scanf("%d", &minD[owner_rid]);
            printf("New Maximum time: ");
            scanf("%d", &maxD[owner_rid]);

            FILE *f = fopen("delivery.txt", "w");
            if (f)
            {
                for (int i = 0; i < NUM_RESTAURANTS; i++)
                    fprintf(f, "%d %d\n", minD[i], maxD[i]);
                fclose(f);
            }
            printf("Delivery Time Updated.\n");
        }
        else if (op == 4)
        {
            printf("Owner Logged Out Successfully!\n");
            break;
        }
        else
        {
            printf("Invalid choice.\n");
        }
    }
}


// main function//
int main()
{
    init_files();
    int minD[NUM_RESTAURANTS], maxD[NUM_RESTAURANTS];
    FILE *fd = fopen("delivery.txt","r");
    if (fd) { for (int i=0;i<NUM_RESTAURANTS;i++)
        if (fscanf(fd,"%d %d",&minD[i], &maxD[i])!=2)
        {
            minD[i]=25; maxD[i]=40;
    } fclose(fd); }
    else for (int i=0;i<NUM_RESTAURANTS;i++) { minD[i]=25; maxD[i]=40; }

    while (1) {
        printf("\n---- Dine-In Delight ----\n1) Owner\n2) Customer\n3) Exit\nChoice: ");
        int ch; if (scanf("%d",&ch)!=1) break;
        if (ch==1) {
            int rid = owner_login();
            if (rid == -1) { printf("Owner login failed.\n"); continue; }
            owner_panel(rid, minD, maxD);
        } else if (ch==2) customer_flow(minD, maxD);
        else if (ch==3) { printf("Goodbye! Visit Us Again!\n"); break; }
        else printf("Invalid.\n");
    }
    return 0;
}
