#include"Number.h"
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<iostream>

namespace ilmp{
    using namespace ilmp::utils;

#define INIT_NUMBER       \
do{                       \
    data=value;           \
    ssize=x?(x>0?1:-1):0; \
    value[0]=x*ssize;     \
}while(0)
    Integer::Integer()                    { data=value; ssize=0; }
    Integer::Integer(bool x)              { INIT_NUMBER; }
    Integer::Integer(char x)              { INIT_NUMBER; }
    Integer::Integer(signed char x)       { INIT_NUMBER; }
    Integer::Integer(unsigned char x)     { INIT_NUMBER; }
    Integer::Integer(signed short x)      { INIT_NUMBER; }
    Integer::Integer(unsigned short x)    { INIT_NUMBER; }
    Integer::Integer(signed int x)        { INIT_NUMBER; }
    Integer::Integer(unsigned int x)      { INIT_NUMBER; }
    Integer::Integer(signed long x)       { INIT_NUMBER; }
    Integer::Integer(unsigned long x)     { INIT_NUMBER; }
    Integer::Integer(signed long long x)  { INIT_NUMBER; }
    Integer::Integer(unsigned long long x){ INIT_NUMBER; }
    void Integer::from_int(mp_int x){
        clear();
        INIT_NUMBER;
    }
    void Integer::from_uint(mp_uint x){
        clear();
        INIT_NUMBER;
    }
#undef INIT_NUMBER
    
    Integer::Integer( float x){ data=value; ssize=0; from_float(&x,sizeof(x)); }
    Integer::Integer(double x){ data=value; ssize=0; from_float(&x,sizeof(x)); }

    Integer::Integer(const char *str,int base){
        data=value;
        ssize=0;
        from_str(str,base);
    }
    Integer::~Integer(){ clear(); }
    void Integer::clear(){
        if(data!=value)delete[] data;
        data=value;
        ssize=0;
    }
    
    Integer::operator bool              () const{ return ssize;    }
    Integer::operator char              () const{ return to_int(); }
    Integer::operator signed char       () const{ return to_int(); }
    Integer::operator unsigned char     () const{ return to_uint(); }
    Integer::operator signed short      () const{ return to_int(); }
    Integer::operator unsigned short    () const{ return to_uint(); }
    Integer::operator signed int        () const{ return to_int(); }
    Integer::operator unsigned int      () const{ return to_uint(); }
    Integer::operator signed long       () const{ return to_int(); }
    Integer::operator unsigned long     () const{ return to_uint(); }
    Integer::operator signed long long  () const{ return to_int(); }
    Integer::operator unsigned long long() const{ return to_uint(); }
    Integer::operator float             () const{
        float x;
        to_float(&x,sizeof(x));
        return x;
    }
    Integer::operator double            () const{
        double x;
        to_float(&x,sizeof(x));
        return x;
    }

    void Integer::neg(){ ssize=-ssize; }
    int Integer::sign() const{ return ssize?(ssize>0?1:-1):0; }
    mp_int Integer::size() const{ return ssize<0?-ssize:ssize; }
    mp_int Integer::capacity() const{ return data==value?2:alloc_size; }

    void Integer::swap(Integer &x){
        const size_t n=sizeof(Integer);
        mp_byte_t buffer[n];
        memcpy(buffer,this,n);
        memcpy(this,&x,n);
        memcpy(&x,buffer,n);
        if(  data==x.value)    data=  value;
        if(x.data==  value)  x.data=x.value;
    }

#define TAKE_ASSIGN                 \
do{                                 \
    memcpy(this,&x,sizeof(Integer));\
    if(data==x.value)data=value;    \
    x.data=x.value;                 \
    x.ssize=0;                      \
}while(0)
#define COPY_ASSIGN                                  \
do{                                                  \
    memcpy(this,&x,sizeof(Integer));                 \
    if(data==x.value)data=value;                     \
    else{                                            \
        mp_int asize=size();                         \
        alloc_size=reserve_limbs_lower(asize);       \
        data=new mp_limb_t[alloc_size];              \
        memcpy(data,x.data,asize*sizeof(mp_limb_t)); \
    }                                                \
}while(0)

    Integer::Integer(Integer &&x){ TAKE_ASSIGN; }
    Integer &Integer::operator =(Integer &&x){
        if(this!=&x){
            clear();
            TAKE_ASSIGN;
        }
        return *this;
    }
    Integer::Integer(const Integer &x){ COPY_ASSIGN; }
    Integer &Integer::operator =(const Integer &x){
        if(this!=&x){
            clear();
            COPY_ASSIGN;
        }
        return *this;
    }
#undef TAKE_ASSIGN
#undef COPY_ASSIGN
    
    Integer::Integer(Number &&x){
        data=value;
        ssize=0;
        if(!x.data||!x.ssize)return;
        if(x.dotp==0){
            data=x.data;
            ssize=x.ssize;
            value[0]=x.value[0];
            value[1]=x.value[1];
            if(data==x.value)data=value;
            x.data=nullptr;
        }
        else{
            Integer(x).swap(*this);
        }
    }
    Integer::Integer(const Number &x){
        data=value;
        ssize=0;
        if(!x.data||!x.ssize)return;

        int signx=x.sign();
        mp_int sizex=x.size(),dotpx=x.dotp;
        mp_limb_t carry=0;
        if(dotpx>0&&dotpx<=sizex)
            carry=x.data[dotpx-1]>>MP_LIMB_BITS-1;
        if(sizex<=dotpx){
            if(carry&&sizex==dotpx){
                ssize=signx;
                value[0]=1;
            }
            return;
        }

        mp_int rn=sizex-dotpx+carry;

        if(rn>2){
            alloc_size=reserve_limbs_lower(rn);
            data=new mp_limb_t[alloc_size];
        }

        if(dotpx<=0){
            if(dotpx<0)memset(data,0,-dotpx*sizeof(mp_limb_t));
            memcpy(data-dotpx,x.data,sizex*sizeof(mp_limb_t));
            dotpx=0;
        }
        else{
            carry=ilmp_add_1_(data,x.data+dotpx,sizex-dotpx,carry);
            if(carry)data[rn-1]=1;
            else rn=sizex-dotpx;
        }
        ssize=rn*signx;
    }
    
    mp_int Integer::to_int() const{
        if(!ssize)return 0;
        mp_int ilimb=data[0];
        return ssize>0?ilimb:-ilimb;
    }
    mp_uint Integer::to_uint() const{
        if(!ssize)return 0;
        mp_uint ilimb=data[0];
        return ssize>0?ilimb:-ilimb;
    }

    mp_int Integer::loglimb() const{
        if(!ssize)return MP_MIN_INT;
        return size();
    }
    mp_prec_t Integer::logbit(mp_int shift) const{
        if(!ssize)return -INT_PREC;
        mp_int asize=size(),alog2=MP_LIMB_BITS*asize;
        mp_prec_t ms=0;
        if(asize>=2)ms=data[asize-2]*(1/MP_BASE);
        ms=(ms+data[asize-1])*(1/MP_BASE);
        ms=std::log2(ms);
        //if alog2 and shift have different signs
        if(shift<0)shift+=alog2;
        else ms+=alog2;
        return ms+shift;
    }
    void Integer::normalize(){
        if(data==value)return;
        if(!ssize){
            delete[] data;
            data=value;
            return;
        }

        mp_int nsize=size();

        //realloc
        if(reserve_limbs_upper(nsize)<alloc_size){
            mp_int newcapa=reserve_limbs_lower(nsize);
            mp_ptr newdata=new mp_limb_t[newcapa];
            memcpy(newdata,data,nsize*sizeof(mp_limb_t));
            delete[] data;
            data=newdata;
            alloc_size=newcapa;
        }
    }
    
    //compare(|num1|,|num2|), need(num1!=0, num2!=0)
    //no nan or zero allowed
    int _comparenzabs(const Integer &Num1,const Integer &Num2){
        mp_int na=Num1.size(),nb=Num2.size();
        if(na>nb)return 1;
        if(na<nb)return -1;
        return ilmp_cmp_(Num1.data,Num2.data,na);
        /*
        {
            mp_int na=Num1.size(),nb=Num2.size();
            mp_int ea=na-Num1.dotp,eb=nb-Num2.dotp;
            if(ea>eb)return sign1;
            if(ea<eb)return -sign1;
            mp_ptr pa=Num1.data+na,pb=Num2.data+nb;
            do{
                if(*--pa!=*--pb)
                    return sign1*(*pa>*pb?1:-1);
                --na;--nb;
            } while(na>0&&nb>0);
            int coef=1;
            if(nb>0){
                na=nb;pa=pb;coef=-1;
            }
            while(na>0){
                if(*--pa!=0)return sign1*coef;
                --na;
            }
            return 0;
        }
        */
    }
    int compare(const Integer &Num1,const Integer &Num2,bool abscomp){
        int sign1,sign2;
        if(abscomp){
            sign1=Num1.ssize!=0;
            sign2=Num2.ssize!=0;
        }
        else{
            sign1=Num1.sign();
            sign2=Num2.sign();
        }
        if(sign1>sign2)return 1;
        if(sign1<sign2)return -1;
        if(sign1)return _comparenzabs(Num1,Num2)*sign1;
        return 0;
    }
    bool operator==(const Integer &Num1,const Integer &Num2){ return compare(Num1,Num2)==0; }
    bool operator!=(const Integer &Num1,const Integer &Num2){ return (compare(Num1,Num2)&1)==1; }
    bool operator> (const Integer &Num1,const Integer &Num2){ return compare(Num1,Num2)==1; }
    bool operator>=(const Integer &Num1,const Integer &Num2){ return compare(Num1,Num2)>=0; }
    bool operator< (const Integer &Num1,const Integer &Num2){ return compare(Num2,Num1)==1; }
    bool operator<=(const Integer &Num1,const Integer &Num2){ return compare(Num2,Num1)>=0; }

    Integer operator-(const Integer &Num){
        Integer result(Num);
        result.neg();
        return result;
    }
    Integer operator+(const Integer &Num){
        Integer result(Num);
        return result;
    }

    void mul(Integer &result,const Integer &Num1,const Integer &Num2){
        if(!Num1.ssize||!Num2.ssize){
            result.clear();
            return;
        }

        mp_int size1=Num1.size(),size2=Num2.size();
        int signres=Num1.sign()*Num2.sign();
        mp_int rn=size1+size2,capax=result.capacity();
        mp_srcptr pa=Num1.data+size1;
        mp_srcptr pb=Num2.data+size2;

        mp_int na=size1;
        mp_int nb=size2;
        while(pa[-na]==0)--na;
        while(pb[-nb]==0)--nb;

        mp_ptr pr=result.data;
        mp_int nz=rn-(na+nb);

        if(rn>capax
            ||size2>2&&(&result==&Num1)&&size1>nz
            ||size1>2&&(&result==&Num2)&&size2>nz){
            capax=reserve_limbs_lower(rn);
            pr=new mp_limb_t[capax];
        }

        if(na>=nb)
            ilmp_mul_(pr+nz,pa-na,na,pb-nb,nb);
        else
            ilmp_mul_(pr+nz,pb-nb,nb,pa-na,na);
        rn-=(pr[rn-1]==0);
        if(nz)memset(pr,0,nz*sizeof(mp_limb_t));

        if(pr!=result.data){
            if(result.data!=result.value)delete[] result.data;
            result.data=pr;
            result.alloc_size=capax;
        }

        result.ssize=rn*signres;
        result.normalize();
    }
    Integer operator*(const Integer &Num1,const Integer &Num2){
        Integer result;
        mul(result,Num1,Num2);
        return result;
    }
    Integer &Integer::operator*=(const Integer &Num){
        mul(*this,*this,Num);
        return *this;
    }
    
    void div(Integer &result,const Integer &Num1,const Integer &Num2){
        if(!Num1.ssize||!Num2.ssize){
            if(!Num2.ssize){
                int zero=ilmp_cmp_(Num2.value,Num2.value,1);
                result.value[0]=1/zero;
            }
            result.clear();
            return;
        }

        mp_int size1=Num1.size(),size2=Num2.size();
        int signres=Num1.sign()*Num2.sign();

        int cmpres=_comparenzabs(Num1,Num2);
        if(cmpres<=0){
            result.from_int(signres&~cmpres);
            return;
        }

        mp_int rn=size1-size2+1,capax=result.capacity();
        mp_int nz2=0;
        while(Num2.data[nz2]==0)++nz2;
        mp_ptr pr=result.data;

        if(rn>capax
            ||size2>2&&(&result==&Num1||&result==&Num2)&&rn>nz2){
            capax=reserve_limbs_lower(rn);
            pr=new mp_limb_t[capax];
        }
        size1-=nz2;
        size2-=nz2;
        ilmp_div_(pr,nullptr,Num1.data+nz2,size1,Num2.data+nz2,size2);
        rn-=(pr[rn-1]==0);

        if(pr!=result.data){
            if(result.data!=result.value)delete[] result.data;
            result.data=pr;
            result.alloc_size=capax;
        }

        result.ssize=rn*signres;
        result.normalize();
    }
    Integer operator/(const Integer &Num1,const Integer &Num2){
        Integer result;
        div(result,Num1,Num2);
        return result;
    }
    Integer &Integer::operator/=(const Integer &Num){
        div(*this,*this,Num);
        return *this;
    }

    void Integer::from_str(const char *pstr,int base){
        Number x;
        x.from_str(pstr,base);
        Integer(std::move(x)).swap(*this);
    }
    mp_int Integer::strlen(int base) const{
        Number ref;
        ref.data=data;
        ref.ssize=ssize;
        ref.dotp=0;
        ref.prec=INT_PREC;
        mp_int result=ref.strlen(base);
        ref.data=nullptr;
        return result;
    }
    mp_int Integer::to_str(char *pstr,int base) const{
        Number ref;
        ref.data=data;
        ref.ssize=ssize;
        ref.dotp=0;
        ref.prec=INT_PREC;
        mp_int ret=ref.to_str(pstr,base);
        ref.data=nullptr;
        return ret;
    }

    void Integer::from_float(const void *fptr,mp_int type_bytes,mp_int exp_bits,mp_int hidden_bit){
        Number x;
        x.from_float(fptr,type_bytes,exp_bits,hidden_bit);
        Integer(std::move(x)).swap(*this);
    }
    void Integer::to_float(void *fptr,mp_int type_bytes,mp_int exp_bits,mp_int hidden_bit) const{
        Number ref;
        ref.data=data;
        ref.ssize=ssize;
        ref.dotp=0;
        ref.prec=INT_PREC;
        ref.to_float(fptr,type_bytes,exp_bits,hidden_bit);
        ref.data=nullptr;
    }

    void _addsub(Integer &result,const Integer &Num1,const Integer &Num2,bool is_add){
        if(!Num1.ssize||!Num2.ssize){
            if(!Num2.ssize)result=Num1;
            else {
                result=Num2;
                if(!is_add)result.neg();
            }
            return;
        }

        int sign1=Num1.sign(),sign2=Num2.sign(),signres=sign1;
        mp_int size1=Num1.size(),size2=Num2.size();
        mp_int rn,capax=result.capacity();
        mp_ptr pr=result.data;

        if((sign1==sign2)==is_add){
            rn=1+std::max(size1,size2);
            if(rn>capax){
                capax=reserve_limbs_lower(rn);
                pr=new mp_limb_t[capax];
            }
            mp_int carry;
            if(size1>=size2)
                carry=ilmp_add_(pr,Num1.data,size1,Num2.data,size2);
            else
                carry=ilmp_add_(pr,Num2.data,size2,Num1.data,size1);
            pr[--rn]=carry;
            rn+=carry;
        }
        else{
            int cmp12=_comparenzabs(Num1,Num2);
            if(cmp12==0){
                result.clear();
                return;
            }

            if(cmp12>0){
                rn=size1;
                if(rn>capax){
                    capax=reserve_limbs_lower(rn);
                    pr=new mp_limb_t[capax];
                }
                ilmp_sub_(pr,Num1.data,size1,Num2.data,size2);
            }
            else{
                rn=size2;
                if(rn>capax){
                    capax=reserve_limbs_lower(rn);
                    pr=new mp_limb_t[capax];
                }
                ilmp_sub_(pr,Num2.data,size2,Num1.data,size1);
                signres=-signres;
            }
            while(pr[rn-1]==0)--rn;
        }

        if(pr!=result.data){
            if(result.data!=result.value)delete[] result.data;
            result.data=pr;
            result.alloc_size=capax;
        }
        result.ssize=rn*signres;
    }
    inline void add(Integer &x,const Integer &Num1,const Integer &Num2){
        _addsub(x,Num1,Num2,true);
        x.normalize();
    }
    inline void sub(Integer &x,const Integer &Num1,const Integer &Num2){
        _addsub(x,Num1,Num2,false);
        x.normalize();
    }

    Integer operator+(const Integer &Num1,const Integer &Num2){
        Integer result;
        add(result,Num1,Num2);
        return result;
    }
    Integer operator-(const Integer &Num1,const Integer &Num2){
        Integer result;
        sub(result,Num1,Num2);
        return result;
    }
    Integer &Integer::operator+=(const Integer &Num){
        add(*this,*this,Num);
        return *this;
    }
    Integer &Integer::operator-=(const Integer &Num){
        sub(*this,*this,Num);
        return *this;
    }

    void shift(Integer &result,const Integer &Num,mp_int sh,bool is_shr){
        if(!Num.ssize){
            result=0;
            return;
        }

        mp_uint nsh=sh;
        if(sh<0){
            is_shr=!is_shr;
            nsh=-nsh;
        }

        int nsign=Num.sign();
        mp_int nsize=Num.size();
        mp_int nbits=nsize*MP_LIMB_BITS;
        if(is_shr&&nsh>nbits)nsh=nbits;

        mp_ptr pr=result.data;
        mp_srcptr pn=Num.data;
        int shb=nsh&MP_LIMB_BITS-1;
        mp_int shw=(nsh-shb)/MP_LIMB_BITS;
        mp_int rn=nsize,newsize=0;
        mp_limb_t carry=0;

        if(is_shr){
            rn-=shw;
            carry=(nsign<0);
        }
        else{
            rn+=shw+(shb!=0);
        }

        mp_int rcapa=result.capacity();
        if(rcapa<rn+carry||rcapa>reserve_limbs_upper(rn+carry)){
            newsize=reserve_limbs_lower(rn+carry);
            pr=new mp_limb_t[newsize];
        }

        if(is_shr){
            mp_limb_t non_zero=0;
            if(carry){
                for(mp_int i=0;i<shw;++i)if(pn[i]){
                    non_zero=carry;
                    break;
                }
            }
            if(rn>0){
                if(shb)non_zero|=ilmp_shr_(pr,pn+shw,rn,shb);
                else memcpy(pr,pn+shw,rn*sizeof(mp_limb_t));
            }
            carry=non_zero&&carry;
        }
        else{
            if(shb)pr[shw+nsize]=ilmp_shl_(pr+shw,pn,nsize,shb);
            else memcpy(pr+shw,pn,nsize*sizeof(mp_limb_t));
            memset(pr,0,shw*sizeof(mp_limb_t));
        }

        if(shb&&!pr[rn-1])--rn;

        if(carry&&(pr[rn]=!rn||ilmp_add_1_(pr,pr,rn,1)))++rn;

        if(result.data!=pr){
            result.clear();
            result.data=pr;
            result.alloc_size=newsize;
        }

        result.ssize=rn*nsign;
    }
    Integer operator<<(const Integer &x,mp_int n){
        Integer result;
        shift(result,x,n,false);
        return result;
    }
    Integer operator>>(const Integer &x,mp_int n){
        Integer result;
        shift(result,x,n,true);
        return result;
    }
    Integer &Integer::operator<<=(mp_int n){
        shift(*this,*this,n,false);
        return *this;
    }
    Integer &Integer::operator>>=(mp_int n){
        shift(*this,*this,n,true);
        return *this;
    }

    //convert this into a string in a given base
    std::string Integer::to_string(int base) const{
        std::string str(1+strlen(base),0);
        size_t slen=to_str((char*)str.data(),base);
        str.resize(slen);
        return str;
    }
    std::istream &operator>>(std::istream &is,Integer &val){
        std::string str;
        is>>str;
        val.from_str(str.c_str());
        return is;
    }
    std::ostream &operator<<(std::ostream &os,const Integer &val){
        return os<<val.to_string();
    }
};
