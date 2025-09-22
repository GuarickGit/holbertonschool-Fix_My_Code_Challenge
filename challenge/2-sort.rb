###
#
#  Sort integer arguments (ascending)
#
###

result = []
ARGV.each do |arg|
    # skip if not integer
    next if arg !~ /^-?[0-9]+$/

    # convert to integer
    i_arg = arg.to_i

    # insert result at the right position
    is_inserted = false
    i = 0
    l = result.size
    while !is_inserted && i < l do
        if result[i] < i_arg
            i += 1
        else
            result.insert(i, i_arg)
            is_inserted = true
            break
        end
    end
    result << i_arg if !is_inserted
end

puts result

# Correction :
# Le code initial utilisait `result.insert(i - 1, i_arg)`.
# Cela décalait l’insertion d’une case vers la gauche et provoquait un ordre incorrect :
#   - Les nouveaux nombres n’étaient pas insérés au bon endroit
#   - Les entiers négatifs se retrouvaient systématiquement rejetés à la fin
#
# La solution est de remplacer par `result.insert(i, i_arg)`,
# ce qui insère la valeur exactement à la bonne position trouvée dans la boucle,
# et garantit un tri numérique croissant correct.
