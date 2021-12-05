//defines
#define NUM_OF_BLOCK 4
#include "cache.h"
//global
cache G_cache;
class cache_level{
public:
    unsigned l_cyc;
    unsigned size;
    unsigned assoc;
    unsigned ways;
    unsigned num_of_blocks;
    unsigned num_of_sets;
    tag **tag_arr;
    //
    cache_level(unsigned l_size ,unsigned l_assoc,unsigned l_cyc,unsigned block_size);
    ~cache_level();
}
cache_level::cache_level(unsigned l_size ,unsigned l_assoc,unsigned l_cyc,unsigned block_size){
    this->l_cyc = l_cyc ;
    this->size = l_size;
    this->assoc = l_assoc;
    this->ways = pow(2,assoc);
    this->num_of_blocks = size/block_size;
    this->num_of_sets = num_of_blocks/assoc;
    this->tag_arr = new tag*[way];
    for(int i=0;i<ways;i++){
        this->tag_arr[i] = new tag[num_of_sets];
    }
}
cache_level::~cache_level(){
    for(int i =0;i<ways;i++) {
        delete[] this->tag_arr[i];
    }
}

class cache{
public:
    unsigned mem_cyc;
    unsigned block_size;
    bool write_alloc;
    cache_level *l1;
    cache_level *l2;
    //
    cache(unsigned mem_cyc,unsigned b_size,unsigned wr_alloc,unsigned l1_size ,unsigned l1_assoc,
          unsigned l1_cyc,unsigned l2_size,unsigned l2_assoc,unsigned l2_cyc);
    ~cache();
}
cache::cache(unsigned mem_cyc,unsigned b_size,unsigned wr_alloc,unsigned l1_size ,unsigned l1_assoc,
             unsigned l1_cyc,unsigned l2_size,unsigned l2_assoc,unsigned l2_cyc){
    this->mem_cyc = mem_cyc;
    this->block_size = b_size;
    this->write_alloc = wr_alloc;
    this->l1 = new cache_level(l1_size,l1_assoc,l1_cyc);
    this->l2 = new cache_level(l2_size,l2_assoc,l2_cyc);
}
cache::~cache(){
    delete this->l1;
    delete this->l2;
}

class tag{
public:
    unsigned tag;
    bool valid;
    bool dirty;
    //
    tag();
}

tag::tag(){
    this->tag = 0;
    this->valid = false;
    this->dirty = false;
}
//do outside
tag::tag_update(unsigned tag ,unsigned wr_alloc,bool hit){
    unsigned temp_tag = this->tag;
    if(hit){
        if(wr_alloc){
            this->valid = true;
            this->dirty = true;
        }
        else{
            //do..
            this->valid = true;
            this->dirty = false;
        }
    }
    else{
        if(wr_alloc){
            this->tag = tag;
            if(this->dirty){
                //do...
                this->valid = true;
            }
            else{
               //do...
                this->valid = true;
            }
            this->dirty = true;
        }
        else{

        }
    }
}

void write(unsigned long address){
    //purssing the address, maybe outside
    unsigned offset = ;
    unsigned set = ;
    unsigned tag = ;
    //l1 search
    for(int i=0;i<l1_ways;i++){
        if(l1->tag_arr[i][l1_set] == tag)

    }
    //l2 search

}