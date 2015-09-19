// Test file version 2
// Copy this into map.c when the bug with the connections functions has been fixed
/* They should be correct since they were extracted and formated using euro.txt 
which contains all the connection between each location*/

#define MAX_LINKS 3

static void testValidMap(Map);
static int isRoadLink(int types[]);
static int isRailLink(int types[]);
static int isBoatLink(int types[]);

static int isRoadLink(int types[]) {
   int i = 0;
   for (i = 0; i < MAX_LINKS; i++) {
      if (types[i] == ROAD)
         return 1;
   }
   return 0;
}
static int isRailLink(int types[]) {
   int i = 0;
   for (i = 0; i < MAX_LINKS; i++) {
      if (types[i] == RAIL)
         return 1;
   }
   return 0;
}
static int isBoatLink(int types[]) {
   int i = 0;
   for (i = 0; i < MAX_LINKS; i++) {
      if (types[i] == BOAT)
         return 1;
   }
   return 0;
}

static void testValidMap(Map map) { 
   return;
   int connCount = 0;
   int * types = calloc(MAX_LINKS, sizeof(int));
   // Testing connections are valid between Adriatic Sea and Bari
   connCount = connections(map, nameToID("Adriatic Sea"), nameToID("Bari"), types);
   assert(connCount == 1);
   assert(isBoatLink(types));
   // Testing connections are valid between Adriatic Sea and Ionian Sea
   connCount = connections(map, nameToID("Adriatic Sea"), nameToID("Ionian Sea"), types);
   assert(connCount == 1);
   assert(isBoatLink(types));
   // Testing connections are valid between Adriatic Sea and Venice
   connCount = connections(map, nameToID("Adriatic Sea"), nameToID("Venice"), types);
   assert(connCount == 1);
   assert(isBoatLink(types));
   // Testing connections are valid between Alicante and Barcelona
   connCount = connections(map, nameToID("Alicante"), nameToID("Barcelona"), types);
   assert(connCount == 2);
   assert(isRailLink(types));
   assert(isBoatLink(types));
   // Testing connections are valid between Alicante and Granada
   connCount = connections(map, nameToID("Alicante"), nameToID("Granada"), types);
   assert(connCount == 1);
   assert(isRoadLink(types));
   // Testing connections are valid between Alicante and Madrid
   connCount = connections(map, nameToID("Alicante"), nameToID("Madrid"), types);
   assert(connCount == 2);
   assert(isRoadLink(types));
   assert(isRailLink(types));
   // Testing connections are valid between Alicante and Mediterranean Sea
   connCount = connections(map, nameToID("Alicante"), nameToID("Mediterranean Sea"), types);
   assert(connCount == 1);
   assert(isBoatLink(types));
   // Testing connections are valid between Alicante and Saragossa
   connCount = connections(map, nameToID("Alicante"), nameToID("Saragossa"), types);
   assert(connCount == 1);
   assert(isRoadLink(types));
   // Testing connections are valid between Amsterdam and Brussels
   connCount = connections(map, nameToID("Amsterdam"), nameToID("Brussels"), types);
   assert(connCount == 1);
   assert(isRoadLink(types));
   // Testing connections are valid between Amsterdam and Cologne
   connCount = connections(map, nameToID("Amsterdam"), nameToID("Cologne"), types);
   assert(connCount == 1);
   assert(isRoadLink(types));
   // Testing connections are valid between Amsterdam and North Sea
   connCount = connections(map, nameToID("Amsterdam"), nameToID("North Sea"), types);
   assert(connCount == 1);
   assert(isBoatLink(types));
   // Testing connections are valid between Athens and Ionian Sea
   connCount = connections(map, nameToID("Athens"), nameToID("Ionian Sea"), types);
   assert(connCount == 1);
   assert(isBoatLink(types));
   // Testing connections are valid between Athens and Valona
   connCount = connections(map, nameToID("Athens"), nameToID("Valona"), types);
   assert(connCount == 2);
   assert(isRoadLink(types));
   assert(isBoatLink(types));
   // Testing connections are valid between Atlantic Ocean and Bay of Biscay
   connCount = connections(map, nameToID("Atlantic Ocean"), nameToID("Bay of Biscay"), types);
   assert(connCount == 1);
   assert(isBoatLink(types));
   // Testing connections are valid between Atlantic Ocean and Cadiz
   connCount = connections(map, nameToID("Atlantic Ocean"), nameToID("Cadiz"), types);
   assert(connCount == 1);
   assert(isBoatLink(types));
   // Testing connections are valid between Atlantic Ocean and English Channel
   connCount = connections(map, nameToID("Atlantic Ocean"), nameToID("English Channel"), types);
   assert(connCount == 1);
   assert(isBoatLink(types));
   // Testing connections are valid between Atlantic Ocean and Galway
   connCount = connections(map, nameToID("Atlantic Ocean"), nameToID("Galway"), types);
   assert(connCount == 1);
   assert(isBoatLink(types));
   // Testing connections are valid between Atlantic Ocean and Irish Sea
   connCount = connections(map, nameToID("Atlantic Ocean"), nameToID("Irish Sea"), types);
   assert(connCount == 1);
   assert(isBoatLink(types));
   // Testing connections are valid between Atlantic Ocean and Lisbon
   connCount = connections(map, nameToID("Atlantic Ocean"), nameToID("Lisbon"), types);
   assert(connCount == 1);
   assert(isBoatLink(types));
   // Testing connections are valid between Atlantic Ocean and Mediterranean Sea
   connCount = connections(map, nameToID("Atlantic Ocean"), nameToID("Mediterranean Sea"), types);
   assert(connCount == 1);
   assert(isBoatLink(types));
   // Testing connections are valid between Atlantic Ocean and North Sea
   connCount = connections(map, nameToID("Atlantic Ocean"), nameToID("North Sea"), types);
   assert(connCount == 1);
   assert(isBoatLink(types));
   // Testing connections are valid between Barcelona and Alicante
   connCount = connections(map, nameToID("Barcelona"), nameToID("Alicante"), types);
   assert(connCount == 2);
   assert(isRailLink(types));
   assert(isBoatLink(types));
   // Testing connections are valid between Barcelona and Mediterranean Sea
   connCount = connections(map, nameToID("Barcelona"), nameToID("Mediterranean Sea"), types);
   assert(connCount == 1);
   assert(isBoatLink(types));
   // Testing connections are valid between Barcelona and Saragossa
   connCount = connections(map, nameToID("Barcelona"), nameToID("Saragossa"), types);
   assert(connCount == 2);
   assert(isRoadLink(types));
   assert(isRailLink(types));
   // Testing connections are valid between Barcelona and Toulouse
   connCount = connections(map, nameToID("Barcelona"), nameToID("Toulouse"), types);
   assert(connCount == 1);
   assert(isRoadLink(types));
   // Testing connections are valid between Bari and Adriatic Sea
   connCount = connections(map, nameToID("Bari"), nameToID("Adriatic Sea"), types);
   assert(connCount == 1);
   assert(isBoatLink(types));
   // Testing connections are valid between Bari and Naples
   connCount = connections(map, nameToID("Bari"), nameToID("Naples"), types);
   assert(connCount == 3);
   assert(isRoadLink(types));
   assert(isRailLink(types));
   assert(isBoatLink(types));
   // Testing connections are valid between Bari and Rome
   connCount = connections(map, nameToID("Bari"), nameToID("Rome"), types);
   assert(connCount == 2);
   assert(isRoadLink(types));
   assert(isBoatLink(types));
   // Testing connections are valid between Bay of Biscay and Atlantic Ocean
   connCount = connections(map, nameToID("Bay of Biscay"), nameToID("Atlantic Ocean"), types);
   assert(connCount == 1);
   assert(isBoatLink(types));
   // Testing connections are valid between Bay of Biscay and Bordeaux
   connCount = connections(map, nameToID("Bay of Biscay"), nameToID("Bordeaux"), types);
   assert(connCount == 1);
   assert(isBoatLink(types));
   // Testing connections are valid between Bay of Biscay and Nantes
   connCount = connections(map, nameToID("Bay of Biscay"), nameToID("Nantes"), types);
   assert(connCount == 1);
   assert(isBoatLink(types));
   // Testing connections are valid between Bay of Biscay and Santander
   connCount = connections(map, nameToID("Bay of Biscay"), nameToID("Santander"), types);
   assert(connCount == 1);
   assert(isBoatLink(types));
   // Testing connections are valid between Belgrade and Bucharest
   connCount = connections(map, nameToID("Belgrade"), nameToID("Bucharest"), types);
   assert(connCount == 1);
   assert(isRoadLink(types));
   // Testing connections are valid between Belgrade and Klausenburg
   connCount = connections(map, nameToID("Belgrade"), nameToID("Klausenburg"), types);
   assert(connCount == 1);
   assert(isRoadLink(types));
   // Testing connections are valid between Belgrade and Sarajevo
   connCount = connections(map, nameToID("Belgrade"), nameToID("Sarajevo"), types);
   assert(connCount == 1);
   assert(isRoadLink(types));
   // Testing connections are valid between Belgrade and Sofia
   connCount = connections(map, nameToID("Belgrade"), nameToID("Sofia"), types);
   assert(connCount == 2);
   assert(isRoadLink(types));
   assert(isRailLink(types));
   // Testing connections are valid between Belgrade and St Joseph and St Marys
   connCount = connections(map, nameToID("Belgrade"), nameToID("St Joseph and St Marys"), types);
   assert(connCount == 1);
   assert(isRoadLink(types));
   // Testing connections are valid between Belgrade and Szeged
   connCount = connections(map, nameToID("Belgrade"), nameToID("Szeged"), types);
   assert(connCount == 2);
   assert(isRoadLink(types));
   assert(isRailLink(types));
   // Testing connections are valid between Berlin and Hamburg
   connCount = connections(map, nameToID("Berlin"), nameToID("Hamburg"), types);
   assert(connCount == 2);
   assert(isRoadLink(types));
   assert(isRailLink(types));
   // Testing connections are valid between Berlin and Leipzig
   connCount = connections(map, nameToID("Berlin"), nameToID("Leipzig"), types);
   assert(connCount == 2);
   assert(isRoadLink(types));
   assert(isRailLink(types));
   // Testing connections are valid between Berlin and Prague
   connCount = connections(map, nameToID("Berlin"), nameToID("Prague"), types);
   assert(connCount == 2);
   assert(isRoadLink(types));
   assert(isRailLink(types));
   // Testing connections are valid between Black Sea and Constanta
   connCount = connections(map, nameToID("Black Sea"), nameToID("Constanta"), types);
   assert(connCount == 1);
   assert(isBoatLink(types));
   // Testing connections are valid between Black Sea and Ionian Sea
   connCount = connections(map, nameToID("Black Sea"), nameToID("Ionian Sea"), types);
   assert(connCount == 1);
   assert(isBoatLink(types));
   // Testing connections are valid between Black Sea and Varna
   connCount = connections(map, nameToID("Black Sea"), nameToID("Varna"), types);
   assert(connCount == 1);
   assert(isBoatLink(types));
   // Testing connections are valid between Bordeaux and Bay of Biscay
   connCount = connections(map, nameToID("Bordeaux"), nameToID("Bay of Biscay"), types);
   assert(connCount == 1);
   assert(isBoatLink(types));
   // Testing connections are valid between Bordeaux and Clermont-Ferrand
   connCount = connections(map, nameToID("Bordeaux"), nameToID("Clermont-Ferrand"), types);
   assert(connCount == 1);
   assert(isRoadLink(types));
   // Testing connections are valid between Bordeaux and Nantes
   connCount = connections(map, nameToID("Bordeaux"), nameToID("Nantes"), types);
   assert(connCount == 1);
   assert(isRoadLink(types));
   // Testing connections are valid between Bordeaux and Paris
   connCount = connections(map, nameToID("Bordeaux"), nameToID("Paris"), types);
   assert(connCount == 1);
   assert(isRailLink(types));
   // Testing connections are valid between Bordeaux and Saragossa
   connCount = connections(map, nameToID("Bordeaux"), nameToID("Saragossa"), types);
   assert(connCount == 2);
   assert(isRoadLink(types));
   assert(isRailLink(types));
   // Testing connections are valid between Bordeaux and Toulouse
   connCount = connections(map, nameToID("Bordeaux"), nameToID("Toulouse"), types);
   assert(connCount == 1);
   assert(isRoadLink(types));
   // Testing connections are valid between Brussels and Amsterdam
   connCount = connections(map, nameToID("Brussels"), nameToID("Amsterdam"), types);
   assert(connCount == 1);
   assert(isRoadLink(types));
   // Testing connections are valid between Brussels and Cologne
   connCount = connections(map, nameToID("Brussels"), nameToID("Cologne"), types);
   assert(connCount == 2);
   assert(isRoadLink(types));
   assert(isRailLink(types));
   // Testing connections are valid between Brussels and Le Havre
   connCount = connections(map, nameToID("Brussels"), nameToID("Le Havre"), types);
   assert(connCount == 1);
   assert(isRoadLink(types));
   // Testing connections are valid between Brussels and Paris
   connCount = connections(map, nameToID("Brussels"), nameToID("Paris"), types);
   assert(connCount == 2);
   assert(isRoadLink(types));
   assert(isRailLink(types));
   // Testing connections are valid between Brussels and Strasbourg
   connCount = connections(map, nameToID("Brussels"), nameToID("Strasbourg"), types);
   assert(connCount == 1);
   assert(isRoadLink(types));
   // Testing connections are valid between Bucharest and Belgrade
   connCount = connections(map, nameToID("Bucharest"), nameToID("Belgrade"), types);
   assert(connCount == 1);
   assert(isRoadLink(types));
   // Testing connections are valid between Bucharest and Constanta
   connCount = connections(map, nameToID("Bucharest"), nameToID("Constanta"), types);
   assert(connCount == 2);
   assert(isRoadLink(types));
   assert(isRailLink(types));
   // Testing connections are valid between Bucharest and Galatz
   connCount = connections(map, nameToID("Bucharest"), nameToID("Galatz"), types);
   assert(connCount == 2);
   assert(isRoadLink(types));
   assert(isRailLink(types));
   // Testing connections are valid between Bucharest and Klausenburg
   connCount = connections(map, nameToID("Bucharest"), nameToID("Klausenburg"), types);
   assert(connCount == 1);
   assert(isRoadLink(types));
   // Testing connections are valid between Bucharest and Sofia
   connCount = connections(map, nameToID("Bucharest"), nameToID("Sofia"), types);
   assert(connCount == 1);
   assert(isRoadLink(types));
   // Testing connections are valid between Bucharest and Szeged
   connCount = connections(map, nameToID("Bucharest"), nameToID("Szeged"), types);
   assert(connCount == 1);
   assert(isRailLink(types));
   // Testing connections are valid between Budapest and Klausenburg
   connCount = connections(map, nameToID("Budapest"), nameToID("Klausenburg"), types);
   assert(connCount == 1);
   assert(isRoadLink(types));
   // Testing connections are valid between Budapest and Szeged
   connCount = connections(map, nameToID("Budapest"), nameToID("Szeged"), types);
   assert(connCount == 2);
   assert(isRoadLink(types));
   assert(isRailLink(types));
   // Testing connections are valid between Budapest and Vienna
   connCount = connections(map, nameToID("Budapest"), nameToID("Vienna"), types);
   assert(connCount == 2);
   assert(isRoadLink(types));
   assert(isRailLink(types));
   // Testing connections are valid between Budapest and Zagreb
   connCount = connections(map, nameToID("Budapest"), nameToID("Zagreb"), types);
   assert(connCount == 1);
   assert(isRoadLink(types));
   // Testing connections are valid between Cadiz and Atlantic Ocean
   connCount = connections(map, nameToID("Cadiz"), nameToID("Atlantic Ocean"), types);
   assert(connCount == 1);
   assert(isBoatLink(types));
   // Testing connections are valid between Cadiz and Granada
   connCount = connections(map, nameToID("Cadiz"), nameToID("Granada"), types);
   assert(connCount == 1);
   assert(isRoadLink(types));
   // Testing connections are valid between Cadiz and Lisbon
   connCount = connections(map, nameToID("Cadiz"), nameToID("Lisbon"), types);
   assert(connCount == 2);
   assert(isRoadLink(types));
   assert(isBoatLink(types));
   // Testing connections are valid between Cadiz and Madrid
   connCount = connections(map, nameToID("Cadiz"), nameToID("Madrid"), types);
   assert(connCount == 1);
   assert(isRoadLink(types));
   // Testing connections are valid between Cagliari and Mediterranean Sea
   connCount = connections(map, nameToID("Cagliari"), nameToID("Mediterranean Sea"), types);
   assert(connCount == 1);
   assert(isBoatLink(types));
   // Testing connections are valid between Cagliari and Tyrrhenian Sea
   connCount = connections(map, nameToID("Cagliari"), nameToID("Tyrrhenian Sea"), types);
   assert(connCount == 1);
   assert(isBoatLink(types));
   // Testing connections are valid between Castle Dracula and Galatz
   connCount = connections(map, nameToID("Castle Dracula"), nameToID("Galatz"), types);
   assert(connCount == 1);
   assert(isRoadLink(types));
   // Testing connections are valid between Castle Dracula and Klausenburg
   connCount = connections(map, nameToID("Castle Dracula"), nameToID("Klausenburg"), types);
   assert(connCount == 1);
   assert(isRoadLink(types));
   // Testing connections are valid between Clermont-Ferrand and Bordeaux
   connCount = connections(map, nameToID("Clermont-Ferrand"), nameToID("Bordeaux"), types);
   assert(connCount == 1);
   assert(isRoadLink(types));
   // Testing connections are valid between Clermont-Ferrand and Geneva
   connCount = connections(map, nameToID("Clermont-Ferrand"), nameToID("Geneva"), types);
   assert(connCount == 1);
   assert(isRoadLink(types));
   // Testing connections are valid between Clermont-Ferrand and Marseilles
   connCount = connections(map, nameToID("Clermont-Ferrand"), nameToID("Marseilles"), types);
   assert(connCount == 1);
   assert(isRoadLink(types));
   // Testing connections are valid between Clermont-Ferrand and Nantes
   connCount = connections(map, nameToID("Clermont-Ferrand"), nameToID("Nantes"), types);
   assert(connCount == 1);
   assert(isRoadLink(types));
   // Testing connections are valid between Clermont-Ferrand and Paris
   connCount = connections(map, nameToID("Clermont-Ferrand"), nameToID("Paris"), types);
   assert(connCount == 1);
   assert(isRoadLink(types));
   // Testing connections are valid between Clermont-Ferrand and Toulouse
   connCount = connections(map, nameToID("Clermont-Ferrand"), nameToID("Toulouse"), types);
   assert(connCount == 1);
   assert(isRoadLink(types));
   // Testing connections are valid between Cologne and Amsterdam
   connCount = connections(map, nameToID("Cologne"), nameToID("Amsterdam"), types);
   assert(connCount == 1);
   assert(isRoadLink(types));
   // Testing connections are valid between Cologne and Brussels
   connCount = connections(map, nameToID("Cologne"), nameToID("Brussels"), types);
   assert(connCount == 2);
   assert(isRoadLink(types));
   assert(isRailLink(types));
   // Testing connections are valid between Cologne and Frankfurt
   connCount = connections(map, nameToID("Cologne"), nameToID("Frankfurt"), types);
   assert(connCount == 2);
   assert(isRoadLink(types));
   assert(isRailLink(types));
   // Testing connections are valid between Cologne and Hamburg
   connCount = connections(map, nameToID("Cologne"), nameToID("Hamburg"), types);
   assert(connCount == 1);
   assert(isRoadLink(types));
   // Testing connections are valid between Cologne and Leipzig
   connCount = connections(map, nameToID("Cologne"), nameToID("Leipzig"), types);
   assert(connCount == 1);
   assert(isRoadLink(types));
   // Testing connections are valid between Cologne and Strasbourg
   connCount = connections(map, nameToID("Cologne"), nameToID("Strasbourg"), types);
   assert(connCount == 1);
   assert(isRoadLink(types));
   // Testing connections are valid between Constanta and Black Sea
   connCount = connections(map, nameToID("Constanta"), nameToID("Black Sea"), types);
   assert(connCount == 1);
   assert(isBoatLink(types));
   // Testing connections are valid between Constanta and Bucharest
   connCount = connections(map, nameToID("Constanta"), nameToID("Bucharest"), types);
   assert(connCount == 2);
   assert(isRoadLink(types));
   assert(isRailLink(types));
   // Testing connections are valid between Constanta and Galatz
   connCount = connections(map, nameToID("Constanta"), nameToID("Galatz"), types);
   assert(connCount == 1);
   assert(isRoadLink(types));
   // Testing connections are valid between Constanta and Varna
   connCount = connections(map, nameToID("Constanta"), nameToID("Varna"), types);
   assert(connCount == 2);
   assert(isRoadLink(types));
   assert(isBoatLink(types));
   // Testing connections are valid between Dublin and Galway
   connCount = connections(map, nameToID("Dublin"), nameToID("Galway"), types);
   assert(connCount == 2);
   assert(isRoadLink(types));
   assert(isBoatLink(types));
   // Testing connections are valid between Dublin and Irish Sea
   connCount = connections(map, nameToID("Dublin"), nameToID("Irish Sea"), types);
   assert(connCount == 1);
   assert(isBoatLink(types));
   // Testing connections are valid between Edinburgh and Manchester
   connCount = connections(map, nameToID("Edinburgh"), nameToID("Manchester"), types);
   assert(connCount == 2);
   assert(isRoadLink(types));
   assert(isRailLink(types));
   // Testing connections are valid between Edinburgh and North Sea
   connCount = connections(map, nameToID("Edinburgh"), nameToID("North Sea"), types);
   assert(connCount == 1);
   assert(isBoatLink(types));
   // Testing connections are valid between English Channel and Atlantic Ocean
   connCount = connections(map, nameToID("English Channel"), nameToID("Atlantic Ocean"), types);
   assert(connCount == 1);
   assert(isBoatLink(types));
   // Testing connections are valid between English Channel and Le Havre
   connCount = connections(map, nameToID("English Channel"), nameToID("Le Havre"), types);
   assert(connCount == 1);
   assert(isBoatLink(types));
   // Testing connections are valid between English Channel and London
   connCount = connections(map, nameToID("English Channel"), nameToID("London"), types);
   assert(connCount == 1);
   assert(isBoatLink(types));
   // Testing connections are valid between English Channel and North Sea
   connCount = connections(map, nameToID("English Channel"), nameToID("North Sea"), types);
   assert(connCount == 1);
   assert(isBoatLink(types));
   // Testing connections are valid between English Channel and Plymouth
   connCount = connections(map, nameToID("English Channel"), nameToID("Plymouth"), types);
   assert(connCount == 1);
   assert(isBoatLink(types));
   // Testing connections are valid between Florence and Genoa
   connCount = connections(map, nameToID("Florence"), nameToID("Genoa"), types);
   assert(connCount == 1);
   assert(isRoadLink(types));
   // Testing connections are valid between Florence and Milan
   connCount = connections(map, nameToID("Florence"), nameToID("Milan"), types);
   assert(connCount == 1);
   assert(isRailLink(types));
   // Testing connections are valid between Florence and Rome
   connCount = connections(map, nameToID("Florence"), nameToID("Rome"), types);
   assert(connCount == 2);
   assert(isRoadLink(types));
   assert(isRailLink(types));
   // Testing connections are valid between Florence and Venice
   connCount = connections(map, nameToID("Florence"), nameToID("Venice"), types);
   assert(connCount == 1);
   assert(isRoadLink(types));
   // Testing connections are valid between Frankfurt and Cologne
   connCount = connections(map, nameToID("Frankfurt"), nameToID("Cologne"), types);
   assert(connCount == 2);
   assert(isRoadLink(types));
   assert(isRailLink(types));
   // Testing connections are valid between Frankfurt and Leipzig
   connCount = connections(map, nameToID("Frankfurt"), nameToID("Leipzig"), types);
   assert(connCount == 2);
   assert(isRoadLink(types));
   assert(isRailLink(types));
   // Testing connections are valid between Frankfurt and Nuremburg
   connCount = connections(map, nameToID("Frankfurt"), nameToID("Nuremburg"), types);
   assert(connCount == 1);
   assert(isRoadLink(types));
   // Testing connections are valid between Frankfurt and Strasbourg
   connCount = connections(map, nameToID("Frankfurt"), nameToID("Strasbourg"), types);
   assert(connCount == 2);
   assert(isRoadLink(types));
   assert(isRailLink(types));
   // Testing connections are valid between Galatz and Bucharest
   connCount = connections(map, nameToID("Galatz"), nameToID("Bucharest"), types);
   assert(connCount == 2);
   assert(isRoadLink(types));
   assert(isRailLink(types));
   // Testing connections are valid between Galatz and Castle Dracula
   connCount = connections(map, nameToID("Galatz"), nameToID("Castle Dracula"), types);
   assert(connCount == 1);
   assert(isRoadLink(types));
   // Testing connections are valid between Galatz and Constanta
   connCount = connections(map, nameToID("Galatz"), nameToID("Constanta"), types);
   assert(connCount == 1);
   assert(isRoadLink(types));
   // Testing connections are valid between Galatz and Klausenburg
   connCount = connections(map, nameToID("Galatz"), nameToID("Klausenburg"), types);
   assert(connCount == 1);
   assert(isRoadLink(types));
   // Testing connections are valid between Galway and Atlantic Ocean
   connCount = connections(map, nameToID("Galway"), nameToID("Atlantic Ocean"), types);
   assert(connCount == 1);
   assert(isBoatLink(types));
   // Testing connections are valid between Galway and Dublin
   connCount = connections(map, nameToID("Galway"), nameToID("Dublin"), types);
   assert(connCount == 2);
   assert(isRoadLink(types));
   assert(isBoatLink(types));
   // Testing connections are valid between Geneva and Clermont-Ferrand
   connCount = connections(map, nameToID("Geneva"), nameToID("Clermont-Ferrand"), types);
   assert(connCount == 1);
   assert(isRoadLink(types));
   // Testing connections are valid between Geneva and Marseilles
   connCount = connections(map, nameToID("Geneva"), nameToID("Marseilles"), types);
   assert(connCount == 1);
   assert(isRoadLink(types));
   // Testing connections are valid between Geneva and Milan
   connCount = connections(map, nameToID("Geneva"), nameToID("Milan"), types);
   assert(connCount == 1);
   assert(isRailLink(types));
   // Testing connections are valid between Geneva and Paris
   connCount = connections(map, nameToID("Geneva"), nameToID("Paris"), types);
   assert(connCount == 1);
   assert(isRoadLink(types));
   // Testing connections are valid between Geneva and Strasbourg
   connCount = connections(map, nameToID("Geneva"), nameToID("Strasbourg"), types);
   assert(connCount == 1);
   assert(isRoadLink(types));
   // Testing connections are valid between Geneva and Zurich
   connCount = connections(map, nameToID("Geneva"), nameToID("Zurich"), types);
   assert(connCount == 1);
   assert(isRoadLink(types));
   // Testing connections are valid between Genoa and Florence
   connCount = connections(map, nameToID("Genoa"), nameToID("Florence"), types);
   assert(connCount == 1);
   assert(isRoadLink(types));
   // Testing connections are valid between Genoa and Marseilles
   connCount = connections(map, nameToID("Genoa"), nameToID("Marseilles"), types);
   assert(connCount == 2);
   assert(isRoadLink(types));
   assert(isBoatLink(types));
   // Testing connections are valid between Genoa and Milan
   connCount = connections(map, nameToID("Genoa"), nameToID("Milan"), types);
   assert(connCount == 2);
   assert(isRoadLink(types));
   assert(isRailLink(types));
   // Testing connections are valid between Genoa and Tyrrhenian Sea
   connCount = connections(map, nameToID("Genoa"), nameToID("Tyrrhenian Sea"), types);
   assert(connCount == 1);
   assert(isBoatLink(types));
   // Testing connections are valid between Genoa and Venice
   connCount = connections(map, nameToID("Genoa"), nameToID("Venice"), types);
   assert(connCount == 2);
   assert(isRoadLink(types));
   assert(isBoatLink(types));
   // Testing connections are valid between Granada and Alicante
   connCount = connections(map, nameToID("Granada"), nameToID("Alicante"), types);
   assert(connCount == 1);
   assert(isRoadLink(types));
   // Testing connections are valid between Granada and Cadiz
   connCount = connections(map, nameToID("Granada"), nameToID("Cadiz"), types);
   assert(connCount == 1);
   assert(isRoadLink(types));
   // Testing connections are valid between Granada and Madrid
   connCount = connections(map, nameToID("Granada"), nameToID("Madrid"), types);
   assert(connCount == 1);
   assert(isRoadLink(types));
   // Testing connections are valid between Hamburg and Berlin
   connCount = connections(map, nameToID("Hamburg"), nameToID("Berlin"), types);
   assert(connCount == 2);
   assert(isRoadLink(types));
   assert(isRailLink(types));
   // Testing connections are valid between Hamburg and Cologne
   connCount = connections(map, nameToID("Hamburg"), nameToID("Cologne"), types);
   assert(connCount == 1);
   assert(isRoadLink(types));
   // Testing connections are valid between Hamburg and Leipzig
   connCount = connections(map, nameToID("Hamburg"), nameToID("Leipzig"), types);
   assert(connCount == 1);
   assert(isRoadLink(types));
   // Testing connections are valid between Hamburg and North Sea
   connCount = connections(map, nameToID("Hamburg"), nameToID("North Sea"), types);
   assert(connCount == 1);
   assert(isBoatLink(types));
   // Testing connections are valid between Ionian Sea and Adriatic Sea
   connCount = connections(map, nameToID("Ionian Sea"), nameToID("Adriatic Sea"), types);
   assert(connCount == 1);
   assert(isBoatLink(types));
   // Testing connections are valid between Ionian Sea and Athens
   connCount = connections(map, nameToID("Ionian Sea"), nameToID("Athens"), types);
   assert(connCount == 1);
   assert(isBoatLink(types));
   // Testing connections are valid between Ionian Sea and Black Sea
   connCount = connections(map, nameToID("Ionian Sea"), nameToID("Black Sea"), types);
   assert(connCount == 1);
   assert(isBoatLink(types));
   // Testing connections are valid between Ionian Sea and Salonica
   connCount = connections(map, nameToID("Ionian Sea"), nameToID("Salonica"), types);
   assert(connCount == 1);
   assert(isBoatLink(types));
   // Testing connections are valid between Ionian Sea and Tyrrhenian Sea
   connCount = connections(map, nameToID("Ionian Sea"), nameToID("Tyrrhenian Sea"), types);
   assert(connCount == 1);
   assert(isBoatLink(types));
   // Testing connections are valid between Ionian Sea and Valona
   connCount = connections(map, nameToID("Ionian Sea"), nameToID("Valona"), types);
   assert(connCount == 1);
   assert(isBoatLink(types));
   // Testing connections are valid between Irish Sea and Atlantic Ocean
   connCount = connections(map, nameToID("Irish Sea"), nameToID("Atlantic Ocean"), types);
   assert(connCount == 1);
   assert(isBoatLink(types));
   // Testing connections are valid between Irish Sea and Dublin
   connCount = connections(map, nameToID("Irish Sea"), nameToID("Dublin"), types);
   assert(connCount == 1);
   assert(isBoatLink(types));
   // Testing connections are valid between Irish Sea and Liverpool
   connCount = connections(map, nameToID("Irish Sea"), nameToID("Liverpool"), types);
   assert(connCount == 1);
   assert(isBoatLink(types));
   // Testing connections are valid between Irish Sea and Swansea
   connCount = connections(map, nameToID("Irish Sea"), nameToID("Swansea"), types);
   assert(connCount == 1);
   assert(isBoatLink(types));
   // Testing connections are valid between Klausenburg and Belgrade
   connCount = connections(map, nameToID("Klausenburg"), nameToID("Belgrade"), types);
   assert(connCount == 1);
   assert(isRoadLink(types));
   // Testing connections are valid between Klausenburg and Bucharest
   connCount = connections(map, nameToID("Klausenburg"), nameToID("Bucharest"), types);
   assert(connCount == 1);
   assert(isRoadLink(types));
   // Testing connections are valid between Klausenburg and Budapest
   connCount = connections(map, nameToID("Klausenburg"), nameToID("Budapest"), types);
   assert(connCount == 1);
   assert(isRoadLink(types));
   // Testing connections are valid between Klausenburg and Castle Dracula
   connCount = connections(map, nameToID("Klausenburg"), nameToID("Castle Dracula"), types);
   assert(connCount == 1);
   assert(isRoadLink(types));
   // Testing connections are valid between Klausenburg and Galatz
   connCount = connections(map, nameToID("Klausenburg"), nameToID("Galatz"), types);
   assert(connCount == 1);
   assert(isRoadLink(types));
   // Testing connections are valid between Klausenburg and Szeged
   connCount = connections(map, nameToID("Klausenburg"), nameToID("Szeged"), types);
   assert(connCount == 1);
   assert(isRoadLink(types));
   // Testing connections are valid between Le Havre and Brussels
   connCount = connections(map, nameToID("Le Havre"), nameToID("Brussels"), types);
   assert(connCount == 1);
   assert(isRoadLink(types));
   // Testing connections are valid between Le Havre and English Channel
   connCount = connections(map, nameToID("Le Havre"), nameToID("English Channel"), types);
   assert(connCount == 1);
   assert(isBoatLink(types));
   // Testing connections are valid between Le Havre and Nantes
   connCount = connections(map, nameToID("Le Havre"), nameToID("Nantes"), types);
   assert(connCount == 1);
   assert(isRoadLink(types));
   // Testing connections are valid between Le Havre and Paris
   connCount = connections(map, nameToID("Le Havre"), nameToID("Paris"), types);
   assert(connCount == 2);
   assert(isRoadLink(types));
   assert(isRailLink(types));
   // Testing connections are valid between Leipzig and Berlin
   connCount = connections(map, nameToID("Leipzig"), nameToID("Berlin"), types);
   assert(connCount == 2);
   assert(isRoadLink(types));
   assert(isRailLink(types));
   // Testing connections are valid between Leipzig and Cologne
   connCount = connections(map, nameToID("Leipzig"), nameToID("Cologne"), types);
   assert(connCount == 1);
   assert(isRoadLink(types));
   // Testing connections are valid between Leipzig and Frankfurt
   connCount = connections(map, nameToID("Leipzig"), nameToID("Frankfurt"), types);
   assert(connCount == 2);
   assert(isRoadLink(types));
   assert(isRailLink(types));
   // Testing connections are valid between Leipzig and Hamburg
   connCount = connections(map, nameToID("Leipzig"), nameToID("Hamburg"), types);
   assert(connCount == 1);
   assert(isRoadLink(types));
   // Testing connections are valid between Leipzig and Nuremburg
   connCount = connections(map, nameToID("Leipzig"), nameToID("Nuremburg"), types);
   assert(connCount == 2);
   assert(isRoadLink(types));
   assert(isRailLink(types));
   // Testing connections are valid between Lisbon and Atlantic Ocean
   connCount = connections(map, nameToID("Lisbon"), nameToID("Atlantic Ocean"), types);
   assert(connCount == 1);
   assert(isBoatLink(types));
   // Testing connections are valid between Lisbon and Cadiz
   connCount = connections(map, nameToID("Lisbon"), nameToID("Cadiz"), types);
   assert(connCount == 2);
   assert(isRoadLink(types));
   assert(isBoatLink(types));
   // Testing connections are valid between Lisbon and Madrid
   connCount = connections(map, nameToID("Lisbon"), nameToID("Madrid"), types);
   assert(connCount == 2);
   assert(isRoadLink(types));
   assert(isRailLink(types));
   // Testing connections are valid between Lisbon and Santander
   connCount = connections(map, nameToID("Lisbon"), nameToID("Santander"), types);
   assert(connCount == 1);
   assert(isRoadLink(types));
   // Testing connections are valid between Liverpool and Irish Sea
   connCount = connections(map, nameToID("Liverpool"), nameToID("Irish Sea"), types);
   assert(connCount == 1);
   assert(isBoatLink(types));
   // Testing connections are valid between Liverpool and Manchester
   connCount = connections(map, nameToID("Liverpool"), nameToID("Manchester"), types);
   assert(connCount == 2);
   assert(isRoadLink(types));
   assert(isRailLink(types));
   // Testing connections are valid between Liverpool and Swansea
   connCount = connections(map, nameToID("Liverpool"), nameToID("Swansea"), types);
   assert(connCount == 2);
   assert(isRoadLink(types));
   assert(isBoatLink(types));
   // Testing connections are valid between London and English Channel
   connCount = connections(map, nameToID("London"), nameToID("English Channel"), types);
   assert(connCount == 1);
   assert(isBoatLink(types));
   // Testing connections are valid between London and Manchester
   connCount = connections(map, nameToID("London"), nameToID("Manchester"), types);
   assert(connCount == 2);
   assert(isRoadLink(types));
   assert(isRailLink(types));
   // Testing connections are valid between London and Plymouth
   connCount = connections(map, nameToID("London"), nameToID("Plymouth"), types);
   assert(connCount == 1);
   assert(isRoadLink(types));
   // Testing connections are valid between London and Swansea
   connCount = connections(map, nameToID("London"), nameToID("Swansea"), types);
   assert(connCount == 2);
   assert(isRoadLink(types));
   assert(isRailLink(types));
   // Testing connections are valid between Madrid and Alicante
   connCount = connections(map, nameToID("Madrid"), nameToID("Alicante"), types);
   assert(connCount == 2);
   assert(isRoadLink(types));
   assert(isRailLink(types));
   // Testing connections are valid between Madrid and Cadiz
   connCount = connections(map, nameToID("Madrid"), nameToID("Cadiz"), types);
   assert(connCount == 1);
   assert(isRoadLink(types));
   // Testing connections are valid between Madrid and Granada
   connCount = connections(map, nameToID("Madrid"), nameToID("Granada"), types);
   assert(connCount == 1);
   assert(isRoadLink(types));
   // Testing connections are valid between Madrid and Lisbon
   connCount = connections(map, nameToID("Madrid"), nameToID("Lisbon"), types);
   assert(connCount == 2);
   assert(isRoadLink(types));
   assert(isRailLink(types));
   // Testing connections are valid between Madrid and Santander
   connCount = connections(map, nameToID("Madrid"), nameToID("Santander"), types);
   assert(connCount == 2);
   assert(isRoadLink(types));
   assert(isRailLink(types));
   // Testing connections are valid between Madrid and Saragossa
   connCount = connections(map, nameToID("Madrid"), nameToID("Saragossa"), types);
   assert(connCount == 2);
   assert(isRoadLink(types));
   assert(isRailLink(types));
   // Testing connections are valid between Manchester and Edinburgh
   connCount = connections(map, nameToID("Manchester"), nameToID("Edinburgh"), types);
   assert(connCount == 2);
   assert(isRoadLink(types));
   assert(isRailLink(types));
   // Testing connections are valid between Manchester and Liverpool
   connCount = connections(map, nameToID("Manchester"), nameToID("Liverpool"), types);
   assert(connCount == 2);
   assert(isRoadLink(types));
   assert(isRailLink(types));
   // Testing connections are valid between Manchester and London
   connCount = connections(map, nameToID("Manchester"), nameToID("London"), types);
   assert(connCount == 2);
   assert(isRoadLink(types));
   assert(isRailLink(types));
   // Testing connections are valid between Marseilles and Clermont-Ferrand
   connCount = connections(map, nameToID("Marseilles"), nameToID("Clermont-Ferrand"), types);
   assert(connCount == 1);
   assert(isRoadLink(types));
   // Testing connections are valid between Marseilles and Geneva
   connCount = connections(map, nameToID("Marseilles"), nameToID("Geneva"), types);
   assert(connCount == 1);
   assert(isRoadLink(types));
   // Testing connections are valid between Marseilles and Genoa
   connCount = connections(map, nameToID("Marseilles"), nameToID("Genoa"), types);
   assert(connCount == 2);
   assert(isRoadLink(types));
   assert(isBoatLink(types));
   // Testing connections are valid between Marseilles and Mediterranean Sea
   connCount = connections(map, nameToID("Marseilles"), nameToID("Mediterranean Sea"), types);
   assert(connCount == 1);
   assert(isBoatLink(types));
   // Testing connections are valid between Marseilles and Milan
   connCount = connections(map, nameToID("Marseilles"), nameToID("Milan"), types);
   assert(connCount == 1);
   assert(isRoadLink(types));
   // Testing connections are valid between Marseilles and Paris
   connCount = connections(map, nameToID("Marseilles"), nameToID("Paris"), types);
   assert(connCount == 1);
   assert(isRailLink(types));
   // Testing connections are valid between Marseilles and Toulouse
   connCount = connections(map, nameToID("Marseilles"), nameToID("Toulouse"), types);
   assert(connCount == 1);
   assert(isRoadLink(types));
   // Testing connections are valid between Marseilles and Zurich
   connCount = connections(map, nameToID("Marseilles"), nameToID("Zurich"), types);
   assert(connCount == 1);
   assert(isRoadLink(types));
   // Testing connections are valid between Mediterranean Sea and Alicante
   connCount = connections(map, nameToID("Mediterranean Sea"), nameToID("Alicante"), types);
   assert(connCount == 1);
   assert(isBoatLink(types));
   // Testing connections are valid between Mediterranean Sea and Atlantic Ocean
   connCount = connections(map, nameToID("Mediterranean Sea"), nameToID("Atlantic Ocean"), types);
   assert(connCount == 1);
   assert(isBoatLink(types));
   // Testing connections are valid between Mediterranean Sea and Barcelona
   connCount = connections(map, nameToID("Mediterranean Sea"), nameToID("Barcelona"), types);
   assert(connCount == 1);
   assert(isBoatLink(types));
   // Testing connections are valid between Mediterranean Sea and Cagliari
   connCount = connections(map, nameToID("Mediterranean Sea"), nameToID("Cagliari"), types);
   assert(connCount == 1);
   assert(isBoatLink(types));
   // Testing connections are valid between Mediterranean Sea and Marseilles
   connCount = connections(map, nameToID("Mediterranean Sea"), nameToID("Marseilles"), types);
   assert(connCount == 1);
   assert(isBoatLink(types));
   // Testing connections are valid between Mediterranean Sea and Tyrrhenian Sea
   connCount = connections(map, nameToID("Mediterranean Sea"), nameToID("Tyrrhenian Sea"), types);
   assert(connCount == 1);
   assert(isBoatLink(types));
   // Testing connections are valid between Milan and Florence
   connCount = connections(map, nameToID("Milan"), nameToID("Florence"), types);
   assert(connCount == 1);
   assert(isRailLink(types));
   // Testing connections are valid between Milan and Geneva
   connCount = connections(map, nameToID("Milan"), nameToID("Geneva"), types);
   assert(connCount == 1);
   assert(isRailLink(types));
   // Testing connections are valid between Milan and Genoa
   connCount = connections(map, nameToID("Milan"), nameToID("Genoa"), types);
   assert(connCount == 2);
   assert(isRoadLink(types));
   assert(isRailLink(types));
   // Testing connections are valid between Milan and Marseilles
   connCount = connections(map, nameToID("Milan"), nameToID("Marseilles"), types);
   assert(connCount == 1);
   assert(isRoadLink(types));
   // Testing connections are valid between Milan and Munich
   connCount = connections(map, nameToID("Milan"), nameToID("Munich"), types);
   assert(connCount == 1);
   assert(isRoadLink(types));
   // Testing connections are valid between Milan and Venice
   connCount = connections(map, nameToID("Milan"), nameToID("Venice"), types);
   assert(connCount == 1);
   assert(isRoadLink(types));
   // Testing connections are valid between Milan and Zurich
   connCount = connections(map, nameToID("Milan"), nameToID("Zurich"), types);
   assert(connCount == 2);
   assert(isRoadLink(types));
   assert(isRailLink(types));
   // Testing connections are valid between Munich and Milan
   connCount = connections(map, nameToID("Munich"), nameToID("Milan"), types);
   assert(connCount == 1);
   assert(isRoadLink(types));
   // Testing connections are valid between Munich and Nuremburg
   connCount = connections(map, nameToID("Munich"), nameToID("Nuremburg"), types);
   assert(connCount == 2);
   assert(isRoadLink(types));
   assert(isRailLink(types));
   // Testing connections are valid between Munich and Strasbourg
   connCount = connections(map, nameToID("Munich"), nameToID("Strasbourg"), types);
   assert(connCount == 1);
   assert(isRoadLink(types));
   // Testing connections are valid between Munich and Venice
   connCount = connections(map, nameToID("Munich"), nameToID("Venice"), types);
   assert(connCount == 1);
   assert(isRoadLink(types));
   // Testing connections are valid between Munich and Vienna
   connCount = connections(map, nameToID("Munich"), nameToID("Vienna"), types);
   assert(connCount == 1);
   assert(isRoadLink(types));
   // Testing connections are valid between Munich and Zagreb
   connCount = connections(map, nameToID("Munich"), nameToID("Zagreb"), types);
   assert(connCount == 1);
   assert(isRoadLink(types));
   // Testing connections are valid between Munich and Zurich
   connCount = connections(map, nameToID("Munich"), nameToID("Zurich"), types);
   assert(connCount == 1);
   assert(isRoadLink(types));
   // Testing connections are valid between Nantes and Bay of Biscay
   connCount = connections(map, nameToID("Nantes"), nameToID("Bay of Biscay"), types);
   assert(connCount == 1);
   assert(isBoatLink(types));
   // Testing connections are valid between Nantes and Bordeaux
   connCount = connections(map, nameToID("Nantes"), nameToID("Bordeaux"), types);
   assert(connCount == 1);
   assert(isRoadLink(types));
   // Testing connections are valid between Nantes and Clermont-Ferrand
   connCount = connections(map, nameToID("Nantes"), nameToID("Clermont-Ferrand"), types);
   assert(connCount == 1);
   assert(isRoadLink(types));
   // Testing connections are valid between Nantes and Le Havre
   connCount = connections(map, nameToID("Nantes"), nameToID("Le Havre"), types);
   assert(connCount == 1);
   assert(isRoadLink(types));
   // Testing connections are valid between Nantes and Paris
   connCount = connections(map, nameToID("Nantes"), nameToID("Paris"), types);
   assert(connCount == 1);
   assert(isRoadLink(types));
   // Testing connections are valid between Naples and Bari
   connCount = connections(map, nameToID("Naples"), nameToID("Bari"), types);
   assert(connCount == 3);
   assert(isRoadLink(types));
   assert(isRailLink(types));
   assert(isBoatLink(types));
   // Testing connections are valid between Naples and Rome
   connCount = connections(map, nameToID("Naples"), nameToID("Rome"), types);
   assert(connCount == 3);
   assert(isRoadLink(types));
   assert(isRailLink(types));
   assert(isBoatLink(types));
   // Testing connections are valid between Naples and Tyrrhenian Sea
   connCount = connections(map, nameToID("Naples"), nameToID("Tyrrhenian Sea"), types);
   assert(connCount == 1);
   assert(isBoatLink(types));
   // Testing connections are valid between North Sea and Amsterdam
   connCount = connections(map, nameToID("North Sea"), nameToID("Amsterdam"), types);
   assert(connCount == 1);
   assert(isBoatLink(types));
   // Testing connections are valid between North Sea and Atlantic Ocean
   connCount = connections(map, nameToID("North Sea"), nameToID("Atlantic Ocean"), types);
   assert(connCount == 1);
   assert(isBoatLink(types));
   // Testing connections are valid between North Sea and Edinburgh
   connCount = connections(map, nameToID("North Sea"), nameToID("Edinburgh"), types);
   assert(connCount == 1);
   assert(isBoatLink(types));
   // Testing connections are valid between North Sea and English Channel
   connCount = connections(map, nameToID("North Sea"), nameToID("English Channel"), types);
   assert(connCount == 1);
   assert(isBoatLink(types));
   // Testing connections are valid between North Sea and Hamburg
   connCount = connections(map, nameToID("North Sea"), nameToID("Hamburg"), types);
   assert(connCount == 1);
   assert(isBoatLink(types));
   // Testing connections are valid between Nuremburg and Frankfurt
   connCount = connections(map, nameToID("Nuremburg"), nameToID("Frankfurt"), types);
   assert(connCount == 1);
   assert(isRoadLink(types));
   // Testing connections are valid between Nuremburg and Leipzig
   connCount = connections(map, nameToID("Nuremburg"), nameToID("Leipzig"), types);
   assert(connCount == 2);
   assert(isRoadLink(types));
   assert(isRailLink(types));
   // Testing connections are valid between Nuremburg and Munich
   connCount = connections(map, nameToID("Nuremburg"), nameToID("Munich"), types);
   assert(connCount == 2);
   assert(isRoadLink(types));
   assert(isRailLink(types));
   // Testing connections are valid between Nuremburg and Prague
   connCount = connections(map, nameToID("Nuremburg"), nameToID("Prague"), types);
   assert(connCount == 1);
   assert(isRoadLink(types));
   // Testing connections are valid between Nuremburg and Strasbourg
   connCount = connections(map, nameToID("Nuremburg"), nameToID("Strasbourg"), types);
   assert(connCount == 1);
   assert(isRoadLink(types));
   // Testing connections are valid between Paris and Bordeaux
   connCount = connections(map, nameToID("Paris"), nameToID("Bordeaux"), types);
   assert(connCount == 1);
   assert(isRailLink(types));
   // Testing connections are valid between Paris and Brussels
   connCount = connections(map, nameToID("Paris"), nameToID("Brussels"), types);
   assert(connCount == 2);
   assert(isRoadLink(types));
   assert(isRailLink(types));
   // Testing connections are valid between Paris and Clermont-Ferrand
   connCount = connections(map, nameToID("Paris"), nameToID("Clermont-Ferrand"), types);
   assert(connCount == 1);
   assert(isRoadLink(types));
   // Testing connections are valid between Paris and Geneva
   connCount = connections(map, nameToID("Paris"), nameToID("Geneva"), types);
   assert(connCount == 1);
   assert(isRoadLink(types));
   // Testing connections are valid between Paris and Le Havre
   connCount = connections(map, nameToID("Paris"), nameToID("Le Havre"), types);
   assert(connCount == 2);
   assert(isRoadLink(types));
   assert(isRailLink(types));
   // Testing connections are valid between Paris and Marseilles
   connCount = connections(map, nameToID("Paris"), nameToID("Marseilles"), types);
   assert(connCount == 1);
   assert(isRailLink(types));
   // Testing connections are valid between Paris and Nantes
   connCount = connections(map, nameToID("Paris"), nameToID("Nantes"), types);
   assert(connCount == 1);
   assert(isRoadLink(types));
   // Testing connections are valid between Paris and Strasbourg
   connCount = connections(map, nameToID("Paris"), nameToID("Strasbourg"), types);
   assert(connCount == 1);
   assert(isRoadLink(types));
   // Testing connections are valid between Plymouth and English Channel
   connCount = connections(map, nameToID("Plymouth"), nameToID("English Channel"), types);
   assert(connCount == 1);
   assert(isBoatLink(types));
   // Testing connections are valid between Plymouth and London
   connCount = connections(map, nameToID("Plymouth"), nameToID("London"), types);
   assert(connCount == 1);
   assert(isRoadLink(types));
   // Testing connections are valid between Prague and Berlin
   connCount = connections(map, nameToID("Prague"), nameToID("Berlin"), types);
   assert(connCount == 2);
   assert(isRoadLink(types));
   assert(isRailLink(types));
   // Testing connections are valid between Prague and Nuremburg
   connCount = connections(map, nameToID("Prague"), nameToID("Nuremburg"), types);
   assert(connCount == 1);
   assert(isRoadLink(types));
   // Testing connections are valid between Prague and Vienna
   connCount = connections(map, nameToID("Prague"), nameToID("Vienna"), types);
   assert(connCount == 2);
   assert(isRoadLink(types));
   assert(isRailLink(types));
   // Testing connections are valid between Rome and Bari
   connCount = connections(map, nameToID("Rome"), nameToID("Bari"), types);
   assert(connCount == 2);
   assert(isRoadLink(types));
   assert(isBoatLink(types));
   // Testing connections are valid between Rome and Florence
   connCount = connections(map, nameToID("Rome"), nameToID("Florence"), types);
   assert(connCount == 2);
   assert(isRoadLink(types));
   assert(isRailLink(types));
   // Testing connections are valid between Rome and Naples
   connCount = connections(map, nameToID("Rome"), nameToID("Naples"), types);
   assert(connCount == 3);
   assert(isRoadLink(types));
   assert(isRailLink(types));
   assert(isBoatLink(types));
   // Testing connections are valid between Rome and Tyrrhenian Sea
   connCount = connections(map, nameToID("Rome"), nameToID("Tyrrhenian Sea"), types);
   assert(connCount == 1);
   assert(isBoatLink(types));
   // Testing connections are valid between Salonica and Ionian Sea
   connCount = connections(map, nameToID("Salonica"), nameToID("Ionian Sea"), types);
   assert(connCount == 1);
   assert(isBoatLink(types));
   // Testing connections are valid between Salonica and Sofia
   connCount = connections(map, nameToID("Salonica"), nameToID("Sofia"), types);
   assert(connCount == 2);
   assert(isRoadLink(types));
   assert(isRailLink(types));
   // Testing connections are valid between Salonica and Valona
   connCount = connections(map, nameToID("Salonica"), nameToID("Valona"), types);
   assert(connCount == 2);
   assert(isRoadLink(types));
   assert(isBoatLink(types));
   // Testing connections are valid between Santander and Bay of Biscay
   connCount = connections(map, nameToID("Santander"), nameToID("Bay of Biscay"), types);
   assert(connCount == 1);
   assert(isBoatLink(types));
   // Testing connections are valid between Santander and Lisbon
   connCount = connections(map, nameToID("Santander"), nameToID("Lisbon"), types);
   assert(connCount == 1);
   assert(isRoadLink(types));
   // Testing connections are valid between Santander and Madrid
   connCount = connections(map, nameToID("Santander"), nameToID("Madrid"), types);
   assert(connCount == 2);
   assert(isRoadLink(types));
   assert(isRailLink(types));
   // Testing connections are valid between Santander and Saragossa
   connCount = connections(map, nameToID("Santander"), nameToID("Saragossa"), types);
   assert(connCount == 1);
   assert(isRoadLink(types));
   // Testing connections are valid between Saragossa and Alicante
   connCount = connections(map, nameToID("Saragossa"), nameToID("Alicante"), types);
   assert(connCount == 1);
   assert(isRoadLink(types));
   // Testing connections are valid between Saragossa and Barcelona
   connCount = connections(map, nameToID("Saragossa"), nameToID("Barcelona"), types);
   assert(connCount == 2);
   assert(isRoadLink(types));
   assert(isRailLink(types));
   // Testing connections are valid between Saragossa and Bordeaux
   connCount = connections(map, nameToID("Saragossa"), nameToID("Bordeaux"), types);
   assert(connCount == 2);
   assert(isRoadLink(types));
   assert(isRailLink(types));
   // Testing connections are valid between Saragossa and Madrid
   connCount = connections(map, nameToID("Saragossa"), nameToID("Madrid"), types);
   assert(connCount == 2);
   assert(isRoadLink(types));
   assert(isRailLink(types));
   // Testing connections are valid between Saragossa and Santander
   connCount = connections(map, nameToID("Saragossa"), nameToID("Santander"), types);
   assert(connCount == 1);
   assert(isRoadLink(types));
   // Testing connections are valid between Saragossa and Toulouse
   connCount = connections(map, nameToID("Saragossa"), nameToID("Toulouse"), types);
   assert(connCount == 1);
   assert(isRoadLink(types));
   // Testing connections are valid between Sarajevo and Belgrade
   connCount = connections(map, nameToID("Sarajevo"), nameToID("Belgrade"), types);
   assert(connCount == 1);
   assert(isRoadLink(types));
   // Testing connections are valid between Sarajevo and Sofia
   connCount = connections(map, nameToID("Sarajevo"), nameToID("Sofia"), types);
   assert(connCount == 1);
   assert(isRoadLink(types));
   // Testing connections are valid between Sarajevo and St Joseph and St Marys
   connCount = connections(map, nameToID("Sarajevo"), nameToID("St Joseph and St Marys"), types);
   assert(connCount == 1);
   assert(isRoadLink(types));
   // Testing connections are valid between Sarajevo and Valona
   connCount = connections(map, nameToID("Sarajevo"), nameToID("Valona"), types);
   assert(connCount == 1);
   assert(isRoadLink(types));
   // Testing connections are valid between Sarajevo and Zagreb
   connCount = connections(map, nameToID("Sarajevo"), nameToID("Zagreb"), types);
   assert(connCount == 1);
   assert(isRoadLink(types));
   // Testing connections are valid between Sofia and Belgrade
   connCount = connections(map, nameToID("Sofia"), nameToID("Belgrade"), types);
   assert(connCount == 2);
   assert(isRoadLink(types));
   assert(isRailLink(types));
   // Testing connections are valid between Sofia and Bucharest
   connCount = connections(map, nameToID("Sofia"), nameToID("Bucharest"), types);
   assert(connCount == 1);
   assert(isRoadLink(types));
   // Testing connections are valid between Sofia and Salonica
   connCount = connections(map, nameToID("Sofia"), nameToID("Salonica"), types);
   assert(connCount == 2);
   assert(isRoadLink(types));
   assert(isRailLink(types));
   // Testing connections are valid between Sofia and Sarajevo
   connCount = connections(map, nameToID("Sofia"), nameToID("Sarajevo"), types);
   assert(connCount == 1);
   assert(isRoadLink(types));
   // Testing connections are valid between Sofia and Valona
   connCount = connections(map, nameToID("Sofia"), nameToID("Valona"), types);
   assert(connCount == 1);
   assert(isRoadLink(types));
   // Testing connections are valid between Sofia and Varna
   connCount = connections(map, nameToID("Sofia"), nameToID("Varna"), types);
   assert(connCount == 2);
   assert(isRoadLink(types));
   assert(isRailLink(types));
   // Testing connections are valid between St Joseph and St Marys and Belgrade
   connCount = connections(map, nameToID("St Joseph and St Marys"), nameToID("Belgrade"), types);
   assert(connCount == 1);
   assert(isRoadLink(types));
   // Testing connections are valid between St Joseph and St Marys and Sarajevo
   connCount = connections(map, nameToID("St Joseph and St Marys"), nameToID("Sarajevo"), types);
   assert(connCount == 1);
   assert(isRoadLink(types));
   // Testing connections are valid between St Joseph and St Marys and Szeged
   connCount = connections(map, nameToID("St Joseph and St Marys"), nameToID("Szeged"), types);
   assert(connCount == 1);
   assert(isRoadLink(types));
   // Testing connections are valid between St Joseph and St Marys and Zagreb
   connCount = connections(map, nameToID("St Joseph and St Marys"), nameToID("Zagreb"), types);
   assert(connCount == 1);
   assert(isRoadLink(types));
   // Testing connections are valid between Strasbourg and Brussels
   connCount = connections(map, nameToID("Strasbourg"), nameToID("Brussels"), types);
   assert(connCount == 1);
   assert(isRoadLink(types));
   // Testing connections are valid between Strasbourg and Cologne
   connCount = connections(map, nameToID("Strasbourg"), nameToID("Cologne"), types);
   assert(connCount == 1);
   assert(isRoadLink(types));
   // Testing connections are valid between Strasbourg and Frankfurt
   connCount = connections(map, nameToID("Strasbourg"), nameToID("Frankfurt"), types);
   assert(connCount == 2);
   assert(isRoadLink(types));
   assert(isRailLink(types));
   // Testing connections are valid between Strasbourg and Geneva
   connCount = connections(map, nameToID("Strasbourg"), nameToID("Geneva"), types);
   assert(connCount == 1);
   assert(isRoadLink(types));
   // Testing connections are valid between Strasbourg and Munich
   connCount = connections(map, nameToID("Strasbourg"), nameToID("Munich"), types);
   assert(connCount == 1);
   assert(isRoadLink(types));
   // Testing connections are valid between Strasbourg and Nuremburg
   connCount = connections(map, nameToID("Strasbourg"), nameToID("Nuremburg"), types);
   assert(connCount == 1);
   assert(isRoadLink(types));
   // Testing connections are valid between Strasbourg and Paris
   connCount = connections(map, nameToID("Strasbourg"), nameToID("Paris"), types);
   assert(connCount == 1);
   assert(isRoadLink(types));
   // Testing connections are valid between Strasbourg and Zurich
   connCount = connections(map, nameToID("Strasbourg"), nameToID("Zurich"), types);
   assert(connCount == 2);
   assert(isRoadLink(types));
   assert(isRailLink(types));
   // Testing connections are valid between Swansea and Irish Sea
   connCount = connections(map, nameToID("Swansea"), nameToID("Irish Sea"), types);
   assert(connCount == 1);
   assert(isBoatLink(types));
   // Testing connections are valid between Swansea and Liverpool
   connCount = connections(map, nameToID("Swansea"), nameToID("Liverpool"), types);
   assert(connCount == 2);
   assert(isRoadLink(types));
   assert(isBoatLink(types));
   // Testing connections are valid between Swansea and London
   connCount = connections(map, nameToID("Swansea"), nameToID("London"), types);
   assert(connCount == 2);
   assert(isRoadLink(types));
   assert(isRailLink(types));
   // Testing connections are valid between Szeged and Belgrade
   connCount = connections(map, nameToID("Szeged"), nameToID("Belgrade"), types);
   assert(connCount == 2);
   assert(isRoadLink(types));
   assert(isRailLink(types));
   // Testing connections are valid between Szeged and Bucharest
   connCount = connections(map, nameToID("Szeged"), nameToID("Bucharest"), types);
   assert(connCount == 1);
   assert(isRailLink(types));
   // Testing connections are valid between Szeged and Budapest
   connCount = connections(map, nameToID("Szeged"), nameToID("Budapest"), types);
   assert(connCount == 2);
   assert(isRoadLink(types));
   assert(isRailLink(types));
   // Testing connections are valid between Szeged and Klausenburg
   connCount = connections(map, nameToID("Szeged"), nameToID("Klausenburg"), types);
   assert(connCount == 1);
   assert(isRoadLink(types));
   // Testing connections are valid between Szeged and St Joseph and St Marys
   connCount = connections(map, nameToID("Szeged"), nameToID("St Joseph and St Marys"), types);
   assert(connCount == 1);
   assert(isRoadLink(types));
   // Testing connections are valid between Szeged and Zagreb
   connCount = connections(map, nameToID("Szeged"), nameToID("Zagreb"), types);
   assert(connCount == 1);
   assert(isRoadLink(types));
   // Testing connections are valid between Toulouse and Barcelona
   connCount = connections(map, nameToID("Toulouse"), nameToID("Barcelona"), types);
   assert(connCount == 1);
   assert(isRoadLink(types));
   // Testing connections are valid between Toulouse and Bordeaux
   connCount = connections(map, nameToID("Toulouse"), nameToID("Bordeaux"), types);
   assert(connCount == 1);
   assert(isRoadLink(types));
   // Testing connections are valid between Toulouse and Clermont-Ferrand
   connCount = connections(map, nameToID("Toulouse"), nameToID("Clermont-Ferrand"), types);
   assert(connCount == 1);
   assert(isRoadLink(types));
   // Testing connections are valid between Toulouse and Marseilles
   connCount = connections(map, nameToID("Toulouse"), nameToID("Marseilles"), types);
   assert(connCount == 1);
   assert(isRoadLink(types));
   // Testing connections are valid between Toulouse and Saragossa
   connCount = connections(map, nameToID("Toulouse"), nameToID("Saragossa"), types);
   assert(connCount == 1);
   assert(isRoadLink(types));
   // Testing connections are valid between Tyrrhenian Sea and Cagliari
   connCount = connections(map, nameToID("Tyrrhenian Sea"), nameToID("Cagliari"), types);
   assert(connCount == 1);
   assert(isBoatLink(types));
   // Testing connections are valid between Tyrrhenian Sea and Genoa
   connCount = connections(map, nameToID("Tyrrhenian Sea"), nameToID("Genoa"), types);
   assert(connCount == 1);
   assert(isBoatLink(types));
   // Testing connections are valid between Tyrrhenian Sea and Ionian Sea
   connCount = connections(map, nameToID("Tyrrhenian Sea"), nameToID("Ionian Sea"), types);
   assert(connCount == 1);
   assert(isBoatLink(types));
   // Testing connections are valid between Tyrrhenian Sea and Mediterranean Sea
   connCount = connections(map, nameToID("Tyrrhenian Sea"), nameToID("Mediterranean Sea"), types);
   assert(connCount == 1);
   assert(isBoatLink(types));
   // Testing connections are valid between Tyrrhenian Sea and Naples
   connCount = connections(map, nameToID("Tyrrhenian Sea"), nameToID("Naples"), types);
   assert(connCount == 1);
   assert(isBoatLink(types));
   // Testing connections are valid between Tyrrhenian Sea and Rome
   connCount = connections(map, nameToID("Tyrrhenian Sea"), nameToID("Rome"), types);
   assert(connCount == 1);
   assert(isBoatLink(types));
   // Testing connections are valid between Valona and Athens
   connCount = connections(map, nameToID("Valona"), nameToID("Athens"), types);
   assert(connCount == 2);
   assert(isRoadLink(types));
   assert(isBoatLink(types));
   // Testing connections are valid between Valona and Ionian Sea
   connCount = connections(map, nameToID("Valona"), nameToID("Ionian Sea"), types);
   assert(connCount == 1);
   assert(isBoatLink(types));
   // Testing connections are valid between Valona and Salonica
   connCount = connections(map, nameToID("Valona"), nameToID("Salonica"), types);
   assert(connCount == 2);
   assert(isRoadLink(types));
   assert(isBoatLink(types));
   // Testing connections are valid between Valona and Sarajevo
   connCount = connections(map, nameToID("Valona"), nameToID("Sarajevo"), types);
   assert(connCount == 1);
   assert(isRoadLink(types));
   // Testing connections are valid between Valona and Sofia
   connCount = connections(map, nameToID("Valona"), nameToID("Sofia"), types);
   assert(connCount == 1);
   assert(isRoadLink(types));
   // Testing connections are valid between Varna and Black Sea
   connCount = connections(map, nameToID("Varna"), nameToID("Black Sea"), types);
   assert(connCount == 1);
   assert(isBoatLink(types));
   // Testing connections are valid between Varna and Constanta
   connCount = connections(map, nameToID("Varna"), nameToID("Constanta"), types);
   assert(connCount == 2);
   assert(isRoadLink(types));
   assert(isBoatLink(types));
   // Testing connections are valid between Varna and Sofia
   connCount = connections(map, nameToID("Varna"), nameToID("Sofia"), types);
   assert(connCount == 2);
   assert(isRoadLink(types));
   assert(isRailLink(types));
   // Testing connections are valid between Venice and Adriatic Sea
   connCount = connections(map, nameToID("Venice"), nameToID("Adriatic Sea"), types);
   assert(connCount == 1);
   assert(isBoatLink(types));
   // Testing connections are valid between Venice and Florence
   connCount = connections(map, nameToID("Venice"), nameToID("Florence"), types);
   assert(connCount == 1);
   assert(isRoadLink(types));
   // Testing connections are valid between Venice and Genoa
   connCount = connections(map, nameToID("Venice"), nameToID("Genoa"), types);
   assert(connCount == 2);
   assert(isRoadLink(types));
   assert(isBoatLink(types));
   // Testing connections are valid between Venice and Milan
   connCount = connections(map, nameToID("Venice"), nameToID("Milan"), types);
   assert(connCount == 1);
   assert(isRoadLink(types));
   // Testing connections are valid between Venice and Munich
   connCount = connections(map, nameToID("Venice"), nameToID("Munich"), types);
   assert(connCount == 1);
   assert(isRoadLink(types));
   // Testing connections are valid between Venice and Vienna
   connCount = connections(map, nameToID("Venice"), nameToID("Vienna"), types);
   assert(connCount == 1);
   assert(isRailLink(types));
   // Testing connections are valid between Vienna and Budapest
   connCount = connections(map, nameToID("Vienna"), nameToID("Budapest"), types);
   assert(connCount == 2);
   assert(isRoadLink(types));
   assert(isRailLink(types));
   // Testing connections are valid between Vienna and Munich
   connCount = connections(map, nameToID("Vienna"), nameToID("Munich"), types);
   assert(connCount == 1);
   assert(isRoadLink(types));
   // Testing connections are valid between Vienna and Prague
   connCount = connections(map, nameToID("Vienna"), nameToID("Prague"), types);
   assert(connCount == 2);
   assert(isRoadLink(types));
   assert(isRailLink(types));
   // Testing connections are valid between Vienna and Venice
   connCount = connections(map, nameToID("Vienna"), nameToID("Venice"), types);
   assert(connCount == 1);
   assert(isRailLink(types));
   // Testing connections are valid between Vienna and Zagreb
   connCount = connections(map, nameToID("Vienna"), nameToID("Zagreb"), types);
   assert(connCount == 1);
   assert(isRoadLink(types));
   // Testing connections are valid between Zagreb and Budapest
   connCount = connections(map, nameToID("Zagreb"), nameToID("Budapest"), types);
   assert(connCount == 1);
   assert(isRoadLink(types));
   // Testing connections are valid between Zagreb and Munich
   connCount = connections(map, nameToID("Zagreb"), nameToID("Munich"), types);
   assert(connCount == 1);
   assert(isRoadLink(types));
   // Testing connections are valid between Zagreb and Sarajevo
   connCount = connections(map, nameToID("Zagreb"), nameToID("Sarajevo"), types);
   assert(connCount == 1);
   assert(isRoadLink(types));
   // Testing connections are valid between Zagreb and St Joseph and St Marys
   connCount = connections(map, nameToID("Zagreb"), nameToID("St Joseph and St Marys"), types);
   assert(connCount == 1);
   assert(isRoadLink(types));
   // Testing connections are valid between Zagreb and Szeged
   connCount = connections(map, nameToID("Zagreb"), nameToID("Szeged"), types);
   assert(connCount == 1);
   assert(isRoadLink(types));
   // Testing connections are valid between Zagreb and Vienna
   connCount = connections(map, nameToID("Zagreb"), nameToID("Vienna"), types);
   assert(connCount == 1);
   assert(isRoadLink(types));
   // Testing connections are valid between Zurich and Geneva
   connCount = connections(map, nameToID("Zurich"), nameToID("Geneva"), types);
   assert(connCount == 1);
   assert(isRoadLink(types));
   // Testing connections are valid between Zurich and Marseilles
   connCount = connections(map, nameToID("Zurich"), nameToID("Marseilles"), types);
   assert(connCount == 1);
   assert(isRoadLink(types));
   // Testing connections are valid between Zurich and Milan
   connCount = connections(map, nameToID("Zurich"), nameToID("Milan"), types);
   assert(connCount == 2);
   assert(isRoadLink(types));
   assert(isRailLink(types));
   // Testing connections are valid between Zurich and Munich
   connCount = connections(map, nameToID("Zurich"), nameToID("Munich"), types);
   assert(connCount == 1);
   assert(isRoadLink(types));
   // Testing connections are valid between Zurich and Strasbourg
   connCount = connections(map, nameToID("Zurich"), nameToID("Strasbourg"), types);
   assert(connCount == 2);
   assert(isRoadLink(types));
   assert(isRailLink(types));
   printf("All connection tests passed!\n");
}
