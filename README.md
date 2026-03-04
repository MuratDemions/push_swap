*This project has been created as part of the 42 curriculum by musipit, embostan*

# push_swap

## Description

Push_swap projesinin amacı, verilen integer listesini yalnızca iki stack
(`a` ve `b`) ve sınırlı komut seti kullanarak **en az operasyonla**
sıralamaktır.

Program:

-   Komut satırından aldığı sayıları stack `a`'ya yükler\
-   Stack `b` başlangıçta boştur\
-   Yalnızca izin verilen operasyonları üretir\
-   Çıktı olarak sorting işlemini yapan komut listesini verir

Bu projede klasik sıralama algoritmaları doğrudan kullanılmaz; her şey
push_swap operasyon modeli üzerinden hesaplanır.

------------------------------------------------------------------------

## Allowed Operations

-   `sa`, `sb`, `ss`
-   `pa`, `pb`
-   `ra`, `rb`, `rr`
-   `rra`, `rrb`, `rrr`

Amaç: Stack `a`'yı **ascending** olacak şekilde sıralamak.

------------------------------------------------------------------------

## Compilation

``` bash
make
```

Zorunlu kurallar:

-   `-Wall -Wextra -Werror`
-   Global değişken yok
-   Memory leak yok
-   Makefile relink yapmaz

------------------------------------------------------------------------

## Usage

### Default (Adaptive strategy)

``` bash
./push_swap 4 67 3 87 23
```

### Force specific strategy

``` bash
./push_swap --simple 5 4 3 2 1
./push_swap --medium 5 4 3 2 1
./push_swap --complex 5 4 3 2 1
./push_swap --adaptive 5 4 3 2 1
```

### Benchmark mode

``` bash
./push_swap --bench 4 67 3 87 23
```

Bench mode şunları stderr'e yazar:

-   Disorder yüzdesi
-   Kullanılan strateji ve complexity class
-   Toplam operasyon sayısı
-   Her operasyonun kaç kez kullanıldığı

------------------------------------------------------------------------

## Disorder Metric

Sorting başlamadan önce disorder hesaplanır.

    mistakes / total_pairs

-   0 → tamamen sıralı
-   1 → en kötü durum
-   0--1 arası → kısmi karışıklık

Bu değer adaptive stratejide hangi algoritmanın seçileceğini belirler.

------------------------------------------------------------------------

## Implemented Strategies

### 1️⃣ Simple --- O(n²)

-   Küçük inputlar için
-   Insertion / Selection tarzı yaklaşım
-   Basit ama büyük inputta pahalı

### 2️⃣ Medium --- O(n√n)

-   Chunk-based yaklaşım
-   √n bölümlere ayırma
-   Dengeli performans

### 3️⃣ Complex --- O(n log n)

-   Radix sort adaptasyonu
-   Büyük inputlar için optimize

### 4️⃣ Adaptive Strategy

Disorder'a göre seçim yapar:

  Disorder Range   Strategy   Target Complexity
  ---------------- ---------- -------------------
  \< 0.2           Simple     O(n²)
  0.2 -- 0.5       Medium     O(n√n)
  ≥ 0.5            Complex    O(n log n)

Amaç: Her input tipinde gereksiz operasyon üretmemek.

------------------------------------------------------------------------

## Error Handling

Program şu durumlarda:

    Error

yazar ve çıkar:

-   Integer olmayan argüman
-   Duplicate değer
-   INT sınırı dışı sayı
-   Geçersiz flag

------------------------------------------------------------------------

## Performance Targets

### 100 sayı için

-   \< 2000 → Pass
-   \< 1500 → Good
-   \< 700 → Excellent

### 500 sayı için

-   \< 12000 → Pass
-   \< 8000 → Good
-   \< 5500 → Excellent

------------------------------------------------------------------------

## Bonus -- Checker

Checker programı stdin'den operasyon okuyup sonucu doğrular:

``` bash
./push_swap 4 2 3 1 | ./checker 4 2 3 1
```

-   Sıralı + b boş → `OK`
-   Aksi → `KO`
-   Hatalı input → `Error`

------------------------------------------------------------------------

## Technical Choices

-   Linked list tabanlı stack implementasyonu
-   Memory güvenli parsing
-   Operasyon sayaç sistemi
-   Strategy selector mekanizması
-   Disorder hesaplama fonksiyonu

------------------------------------------------------------------------

## Resources

-   Big-O Notation\
-   Sorting Algorithms\
-   Radix Sort\
-   Stack Data Structure

AI şu amaçlarla kullanıldı:

-   Disorder metriğinin netleştirilmesi\
-   Complexity doğrulaması\
-   Edge-case senaryoları üretimi\
-   Benchmark tasarım kontrolü

Üretilen her kod manuel olarak test edildi ve doğrulandı.