#!/usr/bin/perl

use warnings;
use strict;
die "program x y density" unless (scalar(@ARGV) == 4);
my ($x, $y, $density, $sign) = @ARGV;
my @spli = split(//, $sign);

print "${y}$sign\n";
for (my $i = 0; $i < $y; $i++) {
for (my $j = 0; $j < $x; $j++) {
if (int(rand($y) * 2) < $density) {
print "$spli[1]";
}
else {
print "$spli[0]";
}
}
print "\n";
}
